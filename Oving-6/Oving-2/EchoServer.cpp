#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class EchoServer {
private:
    class Connection {
    public:
        tcp::socket socket;
        Connection(boost::asio::io_service &io_service) : socket(io_service) {}
    };

    boost::asio::io_service io_service;

    tcp::endpoint endpoint;
    tcp::acceptor acceptor;

    void handle_request(shared_ptr<Connection> connection) {
        auto read_buffer = make_shared<boost::asio::streambuf>();
        async_read_until(connection->socket, *read_buffer, "\r\n\r\n",
                         [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
                             if (!ec) {
                                 istream read_stream(read_buffer.get());
                                 std::string line;
                                 getline(read_stream, line);
                                 string request_type = line.substr(0, line.find(' '));

                                 // Only handle GET requests
                                 if(request_type == "GET") {
                                     string request_path = line.substr(line.find(' ') + 1, line.rfind(' ') - line.find(' ') - 1);

                                     ostream response_stream(read_buffer.get());
                                     if(request_path == "/") {
                                         response_stream << "HTTP/1.1 200 OK\r\nContent-Length: 22\r\n\r\nDette er hovedsiden";
                                     } else if(request_path == "/en_side") {
                                         response_stream << "HTTP/1.1 200 OK\r\nContent-Length: 20\r\n\r\nDette er en side";
                                     } else {
                                         response_stream << "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n";
                                     }

                                     async_write(connection->socket, *read_buffer, [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
                                         if (!ec)
                                             handle_request(connection);
                                     });
                                 }
                             }
                         });
    }

    void accept() {
        auto connection = make_shared<Connection>(io_service);
        acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
            accept();
            if (!ec) {
                handle_request(connection);
            }
        });
    }

public:
    EchoServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

    void start() {
        accept();
        io_service.run();
    }
};

int main() {
    EchoServer echo_server;

    cout << "Starting web server on http://localhost:8080" << endl;

    echo_server.start();
}
