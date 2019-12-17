#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

// структура, която съхранява данните за един елемент
struct tree {
	char ime[20];
	tree* parent;
	tree* left;
	tree* right;
};

// добавя елемент в дървото
tree* insert_tree(char ime[],
	tree* parent,
	tree* left,
	tree* right) {
	tree* p;

	p = new tree;
	p->parent = parent;
	p->left = left;
	if (left) left->parent = p;
	p->right = right;
	if (right) right->parent = p;
	strcpy_s(p->ime, ime);

	return p;
}

// търсене на стойност в дървото
tree* search_tree(tree* t, char ime[]) {
	// ако няма дърво, няма какво да търсиме
	if (t == NULL) return NULL;
	// ако сме попаднали на точният елемент - също
	if (strcmp(t->ime, ime) == 0) return t;
	// търсим в едното, после в другото поддърво
	tree* p = search_tree(t->left, ime);
	if (p) return p;
	else return search_tree(t->right, ime);
}

// изтриване на цялото дърво
void delete_tree(tree*& t) {
	// ако няма дърво, няма какво да изтриваме
	if (t == NULL) return;
	// изтриваме поддърветата
	delete_tree(t->left);
	t->left = NULL;
	delete_tree(t->right);
	t->right = NULL;
	// изтриваме самият елемент
	delete t;
	t = NULL;
}

// отпечатване на всеки елемент и неговите родители
void print_tree_children(tree* t) {
	// ако няма дърво, няма и нищо за отпечатване
	if (t == NULL) return;
	// отпечатваме името на човека
	cout << t->ime;
	// отпечатваме наследниците му (за задачата там съхраняваме родителите му)
	if (t->left) cout << "\n - Bashta: " << t->left->ime;
	if (t->right) cout << "\n - Maika: " << t->right->ime;
	cout << endl;
	// изпълняваме същото за поддърветата
	print_tree_children(t->left);
	print_tree_children(t->right);
}


// отпечатване на всеки елемент от дървото
void print_tree(tree* t) {
	// ако няма дърво, няма и нищо за отпечатване
	if (t == NULL) return;
	// отпечатваме името на човека
	cout << t->ime << endl;
	// изпълняваме същото за поддърветата
	print_tree(t->left);
	print_tree(t->right);
}

// отпечатване на наследниците отляво
void print_left_children(tree* t) {
	// ако няма дърво, няма и нищо за отпечатване
	if (t == NULL) return;
	// отпечатваме името на наследниците отляво
	if (t->left) cout << t->left->ime << endl;
	// изпълняваме същото за поддърветата
	print_left_children(t->left);
	print_left_children(t->right);
}

// отпечатване на наследниците отдясно
void print_right_children(tree* t) {
	// ако няма дърво, няма и нищо за отпечатване
	if (t == NULL) return;
	// отпечатваме името на наследниците отдясно
	if (t->right) cout << t->right->ime << endl;
	// изпълняваме същото за поддърветата
	print_right_children(t->left);
	print_right_children(t->right);
}

// отпечатване на листата
void print_no_children(tree* t) {
	// ако няма дърво, няма и нищо за отпечатване
	if (t == NULL) return;
	// ако елемента е листо, отпечатваме го
	if ((t->left == NULL) && (t->right == 0)) cout << t->ime << endl;
	// изпълняваме същото за поддърветата
	print_no_children(t->left);
	print_no_children(t->right);
}

// отпечатване на цялата ни фамилия, като имената на хората са изредени с запетаи
void print_all_zapetai(tree* t, bool first) {
	// ако няма дърво, няма и нищо за отпечатване
	if (t == NULL) return;
	// отпечатваме имената
	if (first) {
		cout << t->ime << ", ";
		first = false;
	}
	if (t->left) cout << t->left->ime << ", ";
	if (t->right) cout << t->right->ime << ", ";
	// изпълняваме същото за поддърветата
	print_all_zapetai(t->left, first);
	print_all_zapetai(t->right, first);
}

// отпечатване на цялата ни фамилия, като се започне от най-възрастните
void print_all_vazrastni(tree* t) {
	// ако няма дърво, няма и нищо за отпечатване
	if (t == NULL) return;
	// изпълняваме същото за поддърветата
	print_all_vazrastni(t->left);
	print_all_vazrastni(t->right);
	// отпечатваме имената
	if (t->left) cout << t->left->ime << ", ";
	if (t->right) cout << t->right->ime << ", ";
	if (t->left != 0 && t->right != 0) cout << t->ime;
}

// отпечатване на цялата ни фамилия(майка, баща, син)
void print_all_mbs(tree* t) {
	// ако няма дърво, няма и нищо за отпечатване
	if (t == NULL) return;
	// отпечатваме имената
	if (t->right) cout << t->right->ime << ", ";
	if (t->left) cout << t->left->ime << ", ";
	if (t) cout << t->ime << endl;
	// изпълняваме същото за поддърветата
	print_all_mbs(t->left);
	print_all_mbs(t->right);
}

// отпечатване на цялата ни фамилия(майка, син, баща)
void print_all_msb(tree* t) {
	// ако няма дърво, няма и нищо за отпечатване
	if (t == NULL) return;
	// отпечатваме имената
	if (t->right) cout << t->right->ime << " ";
	if (t) cout << t->ime << " ";
	if (t->left == 0 && t->right == 0) cout << endl;
	if (t->left) cout << t->left->ime << endl;
	// изпълняваме същото за поддърветата
	print_all_msb(t->left);
	print_all_msb(t->right);
}

// всичките ни предци, за които знаем родителите
void print_all_bez_lista(tree* t) {
	// ако няма дърво, няма и нищо за отпечатване
	if (t == NULL) return;
	// отпечатваме имената
	if (t->left && t->right) cout << t->ime << endl;
	// изпълняваме същото за поддърветата
	print_all_bez_lista(t->left);
	print_all_bez_lista(t->right);
}

int main()
{
	// създаваме празно дърво
	tree* t = NULL;

	char georgi[] = "Georgi";
	char ivan[] = "Ivan";
	char andrei[] = "Andrei";
	char ana[] = "Ana";
	char maria[] = "Maria";
	char boyan[] = "Boyan";
	char tereza[] = "Tereza";

	// попълваме елементите в него
	t = insert_tree(georgi, NULL,
		insert_tree(ivan, NULL,
			insert_tree(andrei, NULL, NULL, NULL),
			insert_tree(ana, NULL, NULL, NULL)
		),
		insert_tree(maria, NULL,
			insert_tree(boyan, NULL, NULL, NULL),
			insert_tree(tereza, NULL, NULL, NULL)
		)
	);
	// отпечатваме дървото
	cout << "VSEKI ZAEDNO S NEGOVITE RODITELI:" << endl;
	print_tree_children(t);


	cout << "\nRODITELI PO BASHTINA LINIA:\n";
	print_tree(t->left);
	cout << "\nRODITELI PO MAICHINA LINIA:\n";
	print_tree(t->right);

	cout << "\nRODITELI MAJE:\n";
	print_left_children(t);
	cout << "\nRODITELI JENI:\n";
	print_right_children(t);

	cout << "\nBEZ RODITELI:\n";
	print_no_children(t);

	cout << "\nTARSENE NA ANA:\n";
	if (search_tree(t, ana))
		cout << "V roda vi ima Ana.\n";
	else cout << "V roda vi niama Ana.\n";

	cout << "\nVSICHKI IZREDENI S ZAPETAI:\n";
	print_all_zapetai(t, true);
	cout << endl;

	cout << "\nVSICHKI KATO SE ZAPOCHNE OT NAI-VAZRASTNITE\n";
	print_all_vazrastni(t);
	cout << endl;

	cout << "\nVSICHKI V REDA MAIKA, BASHTA, SIN\n";
	print_all_mbs(t);

	cout << "\nVSICHKI V REDA MAIKA, SIN, BASHTA\n";
	print_all_msb(t);

	cout << "\nVSICHKI ZA KOITO ZNAEM RODITELITE\n";
	print_all_bez_lista(t);

	// освобождаваме заеманата памет
	delete_tree(t);


	return 0;
}