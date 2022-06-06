#ifndef COMMAND
#define COMMAND
#include <iostream>
/*Commands to support:
	open
	close
	save
	save_as
	help
	exit

	add_planet
	create_jedi
	remove_jedi
	promote_jedi
	demote_jedi
	get_strongest_jedi
	get_youngest_jedi 
	get_most_used_saber_color (rank or GRAND_MASTER)
	print (planet_name or jedi_name)
	planet_name + planet_name
*/
class Command {
private:
	virtual void doExecute(const size_t)=0;
public:
	virtual ~Command() = default;
	void execute(const size_t commandToExec=0) { doExecute(commandToExec); }
};
class Invalid :public Command {
private:
	std::ostream& output;
	void doExecute(const size_t value=0) {
		output << "INVALID COMMAND! Type help to view commands\n";
	}
public:
	Invalid(std::ostream& out) :output{ out } {}

};
class Help :public Command {
private:
	std::ostream& output;
	void noOpenFile() {
		output << "open <file>  -  opens <file>\n"
			<< "help  -  prints this information\n"
			<< "exit  -  exits the program\n";
	}
	void openedFile() {
		output << "add_planet <planet_name>  -  adds new planet\n"
			<< "create_jedi <planet_name> <jedi_name> <jedi_rank> <jedi_age> <saber_color> <jedi_strength>  -  adds new jedi to planet\n"
			<< "removeJedi <jedi_name> <planet_name>  -  removes jedi from planet\n"
			<< "promote_jedi <jedi_name> <multiplier>  -  promotes jedi with a multiplier that is a positive decimal number\n"
			<< "demote_jedi <jedi_name> <multiplier>  -  demotes jedi with a multiplier that is a positive decimal number\n"
			<< "get_strongest_jedi <planet_name>  -  prints out the strongest jedi on the planet\n"
			<< "get_youngest_jedi <planet_name> <jedi_rank>  -  prints out the youngest jedi on the planet with specified rank\n"
			<< "get_most_used_saber_color <planet_name> <jedi_rank>  -  prints out the most used saber color of jedi with specified rank\n"
			<< "get_most_used_saber_color <planet_name>  -  prints out the most used saber color of jedi with rank GRAND_MASTER\n"
			<< "print <planet_name>  -  prints out the specified planet's information\n"
			<< "print <jedi_name>  -  prints out the specified jedi's information\n"
			<< "<planet_name> + <planet_name>  -  prints out the combined planets information\n"
			<< "close  -  closes currently opened file\n"
			<< "save  -  saves the currently opened file\n"
			<< "saveas <file>  -  saves the currently opened file in <file>\n"
			<< "help  -  displays this information\n";
	}
	void doExecute(const size_t value=0) final {
		output << "Commands available:\n";
		if (value == 1)openedFile();
		else noOpenFile();
	}
public:
	Help(std::ostream& out) :output{ out } {}
};
class Exit : public Command {
	std::ostream& output;
	void doExecute(const size_t value = 0) final {
		output << "Exiting program...\n";
	}
public:
	Exit(std::ostream& out):output{ out }{}
};
#endif // !COMMAND

