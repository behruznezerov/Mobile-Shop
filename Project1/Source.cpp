#include <iostream>

using namespace std;


struct Phone {
	char* Vendor = new char[20];
	char* Model = new char[20];
	int ram = 0, storage = 0;
	Phone(const char* _Vendor, const char* _Model, int _ram, int _storage) {
		strcpy_s(Vendor, strlen(_Vendor) + 1, _Vendor);
		strcpy_s(Model, strlen(_Model) + 1, _Model);
		ram = _ram;
		storage = _storage;
	}
};

int ctrPhones = 0;
Phone* phones[20]{};

void addPhone(const char* _Vendor, const char* _Model, int _ram, int _storage) {

	Phone* phone = new Phone(_Vendor, _Model, _ram, _storage);

	phones[ctrPhones] = { phone };

	ctrPhones++;
}

void deletePhone(int row) {

	delete phones[row];

	ctrPhones--;
}

void showPhones() {
	system("cls");
	cout << "Phones" << endl << endl << endl;
	if (ctrPhones != 0) {
		for (size_t i = 0; i < ctrPhones; i++)
			cout << i + 1 << "."
			<< phones[i]->Vendor
			<< " - " << phones[i]->Model
			<< " - " << phones[i]->ram << "GB RAM"
			<< " - " << phones[i]->storage << "GB Storage" << endl << endl;
		cout
			<< "0. Add New Phone" << endl
			<< "-1. Back" << endl
			<< "-2. Delete Phone" << endl << endl;
	}
	else
		cout
		<< "There is no phone, please add a new one" << endl << endl << endl
		<< "0. Add New Phone" << endl
		<< "-1. Back" << endl << endl;
}

void deletePhoneMenu() {
	system("cls");
	cout << "Delete Phones" << endl << endl << endl;
	for (size_t i = 0; i < ctrPhones; i++)
		cout << i + 1 << "."
		<< phones[i]->Vendor
		<< " - " << phones[i]->Model
		<< " - " << phones[i]->ram << "GB RAM"
		<< " - " << phones[i]->storage << "GB Storage" << endl << endl;

	cout
		<< "Delete Phone [row]" << endl
		<< "-1. Back" << endl;
}

void mainMenu() {
	cout
		<< "Main Menu" << endl << endl << endl
		<< "1. Phones" << endl
		<< "2. Exit" << endl << endl;
}

void main() {
	int option = 0;
	system("cls");
main:
	mainMenu();
	cout << "Option: ";
	cin >> option;
	if (!cin) {
		system("cls");
		cout << "Wrong Choice" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		goto main;
	}
	if (option != 1 && option != 2 && option != 3) {
		system("cls");
		cout << "Wrong Choice" << endl;
		goto main;
	}
	else if (option == 1) {
	phone:
		showPhones();
		cout << "Option: ";
		cin >> option;
		if (!cin) {
			system("cls");
			cout << "Wrong Choice" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			goto phone;
		}
		if (option == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			char* vendor = new char[20];
			cout << "Phone Vendor: ";
			cin >> vendor;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			char* model = new char[20];
			cout << "Phone Model: ";
			cin.getline(model, 20);

			int ram = 0;
		ram:
			cout << "Phone Ram: ";
			cin >> ram;
			if (!cin) {
				cout << "Fill the ram correctly!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto ram;
			}
			int storage = 0;
		storage:
			cout << "Phone Storage: ";
			cin >> storage;
			if (!cin) {
				cout << "please fill the storage correctly!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto storage;
			}
			addPhone(vendor, model, ram, storage);
			goto phone;
		}
		else if (option == -2 && ctrPhones > 0) {
		_delete:
			deletePhoneMenu();
			int row = 0;
			cout << "Option: ";
			cin >> row;
			if (!cin) {
				cout << "Wrong Choice" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto _delete;
			}
			if (row == -1) goto phone;

			deletePhone(row);
			goto phone;
		}
		else if (option == -1) {
			system("cls");
			goto main;
		}
		else {
			system("cls");
			cout << "Wrong Operator";
			goto phone;
		}
	}
	else if (option == 2) {
		if (ctrPhones != 0) {
			for (size_t i = 0; i < ctrPhones; i++)
				delete phones[i];
			delete phones;
		}
		ctrPhones = NULL;
		return;
	}
}