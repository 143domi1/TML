#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

using namespace std;
int main() {
    int option;
    cout << "Hello! This is TDM (Teardown mod manager)!\nWhat would you like to do!\n1.Install mod to teardown\n2.Copyright\n";
    cin >> option;
    if (option == 1) {
        string path;
        cout << "Please enter mod path!(Mod path CANNOT have spaces, the program will not work with spaces): \n";
        cin >> path;
        fs::path source = path;
        fs::path destination = getenv("HOME");
        destination /= ".local/share/Steam/steamapps/common/Teardown/mods";

        try {
            fs::copy(source, destination / source.filename(), fs::copy_options::recursive | fs::copy_options::overwrite_existing);
            std::cout << "Mod has been installed successfuly!\n";
        } catch (fs::filesystem_error& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
    //else if (option == 2) {
        //string path;
        //cout << "Please enter mod name (EXACTLY how its called in the mod folder in teardown file's): ";
      //  cin >> path;
    //}
    else {
        cout << "This program is licensed under the GNU General Public License v3 (GPLv3).\nMade by © Domipro143 (GitHub) and its contributors (on GitHub).\nThis program is NOT officially endorsed, approved, or connected to the official Teardown game or its developers.";
    }
}