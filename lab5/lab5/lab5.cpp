#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Programming
{
public:

	//constructors
	Programming() { }
	Programming(string name_lang, string libr) : name_of_language(name_lang), library(libr) { }

	//properties
	string Name_of_language()
	{
		return name_of_language;
	}
	string Library()
	{
		return library;
	}

	//metods
	virtual void Print() = 0;
	virtual string ToString() = 0;

protected:
	string name_of_language = "";
	string library = "";
};

enum class TypesInheritance
{
	SingleInher,
	MultiInher,
	HybridInher
};

string TypeInher(TypesInheritance inher)
{
	switch (inher)
	{
	case TypesInheritance::SingleInher: return "Single Inheritance";
	case TypesInheritance::MultiInher: return "Multi Inheritance";
	case TypesInheritance::HybridInher: return "Hybrid Inheritance";
	}
}

/// <summary>
/// enter int value and return type inheritance
/// </summary>
/// <param name="buf">int value of inheritance: 1-single, 2-multi, 3-hybrid</param>
/// <returns></returns>
TypesInheritance SetInher(int buf)
{
	switch (buf)
	{
	case 1: return TypesInheritance::SingleInher;
	case 2: return TypesInheritance::MultiInher;
	case 3: return TypesInheritance::HybridInher;
	default:
		throw "Index_Not_In_Enum_Value";
		break;
	}
}

class OOP : public Programming
{
public:

	//constructors
	OOP() { };

	OOP(string name_lang, string libr, TypesInheritance inherit, bool auto_encaps, bool true_polymorf) : Programming(name_lang, libr)
	{
		inheritance = inherit;
		automat_Encapsulation = auto_encaps;
		is_true_Polymorphism = true_polymorf;
	}

	//properties
	TypesInheritance Inheritance()
	{
		return inheritance;
	}

	bool Automat_Encapsulation()
	{
		return automat_Encapsulation;
	}

	bool Is_True_Polymorphism()
	{
		return is_true_Polymorphism;
	}

	//methods
	void Print() override
	{
		cout << "Name of language - " << Name_of_language() << ". Using library - " << library << ". Support inheritance - " +
			TypeInher(inheritance) << ". Encapsulation is " << ((automat_Encapsulation) ? "fully " : "not ")
			<< "automated. And Polymorphism " << ((is_true_Polymorphism) ? "is" : "is`n") << " true." << endl;
	}

	string ToString() override
	{
		return "Name of language - " + name_of_language + ". Using library - " + library + ". Support inheritance - " +
			TypeInher(inheritance) + ". Encapsulation is " + ((automat_Encapsulation) ? "fully " : "not ") + "automated. And Polymorphism "
			+ ((is_true_Polymorphism) ? "is" : "is`n") + " true.";
	}

private:
	TypesInheritance inheritance = TypesInheritance::SingleInher;
	bool automat_Encapsulation = false, is_true_Polymorphism = false;
};

class Markup : public Programming
{
public:
	//constructors
	Markup() { }
	Markup(string name_lang, string libr, string tagnam, string framename) : Programming(name_lang, libr)
	{
		tag = tagnam;
		framework = framename;
	}

	//properties
	string Tag()
	{
		return tag;
	}
	string Framework()
	{
		return framework;
	}

	//methods
	void Print() override
	{
		cout << "Name of language - " + name_of_language << ". Using library - " + library << ". Using tag - " + tag << " in framework - "
			+ framework << "." << endl;
	}
	string ToString() override
	{
		return "Name of language - " + name_of_language + ". Using library - " + library + ". Using tag - " + tag + " in framework - "
			+ framework + ".";
	}

private:
	string tag = "", framework = "";
};

enum class SkriptsTargets
{
	ShellScripts,
	AppliedScripts,
	GeneralScripts
};

string ScriptTarget(SkriptsTargets buf)
{
	switch (buf)
	{
	case SkriptsTargets::ShellScripts: return "Shell oriented scripts";
	case SkriptsTargets::AppliedScripts: return "Applied oriented scripts";
	case SkriptsTargets::GeneralScripts: return "General-Purpose scripts";
	}
}

/// <summary>
/// enter int value and return script target
/// </summary>
/// <param name="buf">int value of target: 1-shell, 2-applied, 3-general</param>
/// <returns></returns>
SkriptsTargets SetTargetScript(int buf)
{
	switch (buf)
	{
	case 1: return SkriptsTargets::ShellScripts;
	case 2: return SkriptsTargets::AppliedScripts;
	case 3: return SkriptsTargets::GeneralScripts;
	default:
		throw "Index_Not_In_Enum_Value";
		break;
	}
}

enum class TypeScript
{
	Macro,
	Plugin,
	Normal
};

string TypeOfScript(TypeScript buf)
{
	switch (buf)
	{
	case TypeScript::Macro: return "Macro script";
	case TypeScript::Plugin: return "Plug-in script";
	case TypeScript::Normal: return "Normal script";
	}
}

/// <summary>
/// enter int value and return script type
/// </summary>
/// <param name="buf">int value of target: 1-macro, 2-plugin, 3-normal</param>
/// <returns></returns>
TypeScript SetScriptType(int buf)
{
	switch (buf)
	{
	case 1: return TypeScript::Macro;
	case 2: return TypeScript::Plugin;
	case 3: return TypeScript::Normal;
	default:
		throw "Index_Not_In_Enum_Value";
		break;
	}
}

class Scripts : public Programming
{
public:
	//constructor
	Scripts() { }
	Scripts(string name_lang, string libr, SkriptsTargets target, TypeScript typeSkript) : Programming(name_lang, libr)
	{
		targetting = target;
		type = typeSkript;
	}

	//properties
	SkriptsTargets Targetting()
	{
		return targetting;
	}
	TypeScript Type()
	{
		return type;
	}

	//methods
	void Print() override
	{
		cout << "Name of language - " + name_of_language << ". Using library - " + library << ". Target to " + ScriptTarget(targetting) <<
			" and type is " + TypeOfScript(type) << "." << endl;
	}
	string ToString() override
	{
		return "Name of language - " + name_of_language + ". Using library - " + library + ". Target to " + ScriptTarget(targetting) +
			" and type is " + TypeOfScript(type) + ".";
	}

private:
	SkriptsTargets targetting = SkriptsTargets::GeneralScripts;
	TypeScript type = TypeScript::Normal;
};

int Check()
{
	while (true)
	{
		int a;
		std::cin >> a;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n'); // удаляем лишние значения

			return a;
		}
	}
}

int CheckEnum()
{
	while (true)
	{
		int a;
		std::cin >> a;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');

			if ((a >= 1) && (a <= 3))
			{
				return a;
			}

			std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
	}
}

int CheckBool()
{
	while (true)
	{
		int a;
		std::cin >> a;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');

			if ((a >= 0) && (a <= 1))
			{
				return a;
			}

			std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
	}
}

int main()
{
	cout << "Entering OOP class\n" << "Enter name of language in OOP" << endl;
	string name, libr;
	getline(cin, name);
	cout << "Enter name of using library" << endl;
	getline(cin, libr);
	cout << "Enter type of inheritance:\n1 - single inher\n2 - multi inher\n3 - hybrid inher" << endl;
	TypesInheritance inher = SetInher(CheckEnum());
	cout << "IDE is automatically encapsulating? (1 - yes, 0 - no)" << endl;
	bool auto_encaps = CheckBool(), polymorf;
	cout << "Is it supply true polymorf? (1 - yes, 0 - no)" << endl;
	polymorf = CheckBool();

	OOP oop(name, libr, inher, auto_encaps, polymorf);
	Programming* oops[3];
	oops[0] = &oop;
	oops[0]->Print();
	cout << oops[0]->ToString() << endl;

	cout << "\n----------------------------------------------------------------\n" << endl;

	cout << "Entering Markup class\n" << "Enter name of language in Markup" << endl;
	getline(cin, name);
	cout << "Enter name of using library" << endl;
	getline(cin, libr);
	cout << "Enter using tag" << endl;
	string tag, framework;
	getline(cin, tag);
	cout << "Enter using framework" << endl;
	getline(cin, framework);

	Markup markup(name, libr, tag, framework);
	oops[1] = &markup;
	oops[1]->Print();
	cout << oops[1]->ToString() << endl;
	cout << "\n----------------------------------------------------------------\n" << endl;

	//delete[] oops;

	cout << "Entering Script class\n" << "Enter name of language in Script" << endl;
	getline(cin, name);
	cout << "Enter name of using library" << endl;
	getline(cin, libr);
	cout << "Enter script target:\n1 - shell\n2 - applied\n3 - general" << endl;
	SkriptsTargets target = SetTargetScript(CheckEnum());
	cout << "Enter script type:\n1 - macro\n2 - plugin\n3 - normal" << endl;
	TypeScript type = SetScriptType(CheckEnum());

	Scripts sctipt(name, libr, target, type);
	oops[2] = &sctipt;
	oops[2]->Print();
	cout << oops[2]->ToString() << endl;

	//delete[] oops;
}