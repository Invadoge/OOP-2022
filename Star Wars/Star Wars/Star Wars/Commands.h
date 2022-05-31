#ifndef COMMAND
#define COMMAND

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
	virtual Command* clone()const = 0;
	virtual ~Command() = default;
	void execute(const size_t commandToExec) { doExecute(commandToExec); }
};
#endif // !COMMAND

