#include <gtkmm.h>
#include <gtkmm/cssprovider.h>
#include <glibmm/refptr.h>

class Window : public Gtk::Window {
public:
    Gtk::Box box;
    Gtk::Label label_first_name;
    Gtk::Label label_last_name;
    Gtk::Entry entry_first_name;
    Gtk::Entry entry_last_name;
    Gtk::Button button_combine;
    Gtk::Label label_full_name;

    Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
        set_title("Name Combiner");

        label_first_name.set_text("First Name:");
        label_last_name.set_text("Last Name:");

        button_combine.set_name("combine-button");
        button_combine.set_label("Combine Names");
        button_combine.set_sensitive(false); // Set button insensitive by default

        // Packing the labels and entries into the box
        box.pack_start(label_first_name, Gtk::PACK_SHRINK);    // Add the label for the first name
        box.pack_start(entry_first_name, Gtk::PACK_SHRINK);    // Add the widget for the first name
        box.pack_start(label_last_name, Gtk::PACK_SHRINK);     // Add the label for the last name
        box.pack_start(entry_last_name, Gtk::PACK_SHRINK);     // Add the widget for the last name
        box.pack_start(button_combine, Gtk::PACK_SHRINK);      // Add the combine button
        box.pack_start(label_full_name, Gtk::PACK_SHRINK);     // Add the label to show the full name

        add(box);                            // Add vbox to window
        show_all();                          // Show all widgets

        entry_first_name.signal_changed().connect(sigc::mem_fun(*this, &Window::on_entry_changed));
        entry_last_name.signal_changed().connect(sigc::mem_fun(*this, &Window::on_entry_changed));


        button_combine.signal_clicked().connect([this]() {
            label_full_name.set_text("Full Name: " + entry_first_name.get_text() + " " + entry_last_name.get_text());
        });
    }

    void on_entry_changed() {
        if(!entry_first_name.get_text().empty() && !entry_last_name.get_text().empty()) {
            button_combine.set_sensitive(true);
        } else {
            button_combine.set_sensitive(false);
        }
    }
};

int main() {
    auto app = Gtk::Application::create();
    Window window;

    // Create a CSS provider and load the CSS data
    Glib::RefPtr<Gtk::CssProvider> css_provider = Gtk::CssProvider::create();
    css_provider->load_from_data(
            "#combine-button {"
            "    background-color: blue;"
            "    font-weight: bold;"
            "    font-size: 1.5em;"
            "    border: 1px solid black;"
            "}"
    );


    // Add the CSS provider to the app's default screen
    Gtk::StyleContext::add_provider_for_screen(
            Gdk::Screen::get_default(),
            css_provider,
            GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );


    return app->run(window);
}
