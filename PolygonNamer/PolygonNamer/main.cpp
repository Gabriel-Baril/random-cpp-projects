#include <iostream>
#include <string>
#include <vector>


const char* BASIC_POLY[20] = { "MONOGON","DIGON","TRIGON","TETRAGON","PENTAGON","HEXAGON","HEPTAGON","OCTAGON","ENNEAGON","DECAGON","HENDECAGON","DODECAGON","TRIDECAGON","TETRADECAGON","PENTADECAGON","HEXADECAGON","HEPTADECAGON","OCTADECAGON","ENNEADECAGON","ICOSAGON" };

const char* PREFIX[7][9] =
{
	{"HENA","DI","TRI","TETRA","PENTA","HEXA","HEPTA","OCTO","ENNEA"},
	{"DECA","ICOSI","TRIACONTA","TETRACONTA","PENTACONTA","HEXACONTA","HEPTACONTA","OCTACONTA","ENNEACONTA"},
	{"HECTA","DIHECTA","TRIHECTA","TETRAHECTA","PENTAHECTA","HEXAHECTA","HEPTAHECTA","OCTAHECTA","ENNEAHECTA"},
	{"CHILIA","DISCHILIA","TRISCHILIA","TETRAKISCHILIA","PENTAKISCHILIA","HEXAKISCHILIA","HEPTAKISCHILIA","OCTAKISCHILIA","ENNEAKISCHILIA"},
	{"MYRIA","DISMYRIA","TRISMYRIA","TETRAKISMYRIA","PENTAKISMYRIA","HEXAKISMYRIA","HEPTAKISMYRIA","OCTAKISMYRIA","ENNEAKISMYRIA"},
	{"HUNTHA","DISHUNTHA","TRISHUNTHA","TETRAKISHUNTHA","PENTAKISHUNTHA","HEXAKISHUNTHA","HEPTAKISHUNTHA","OCTAKISHUNTHA","ENNEAKISHUNTHA"},
	{"MEGA","DISMEGA","TRISMEGA","TETRAKISMEGA","PENTAKISMEGA","HEXAKISMEGA","HEPTAKISMEGA","OCTAKISMEGA","ENNEAKISMEGA"}
};

unsigned int getNumberDigit(unsigned int number)
{
	float current = number;
	unsigned int number_digit = 0;
	while (current >= 1)
	{
		current /= 10;
		number_digit++;
	}
	return number_digit;
}

unsigned int getDigitAt(unsigned int number, unsigned int digit)
{
	unsigned nb_digit = getNumberDigit(number);
	unsigned current = number;
	while (nb_digit > digit)
	{
		float multiple = pow(10, nb_digit);
		current -= (unsigned int)( current / multiple ) * multiple;
		nb_digit--;
	}

	return (unsigned int)(current / pow(10,digit));
}

std::vector<std::string> getNames(unsigned int nb_side)
{
	std::vector<std::string> names = std::vector<std::string>();
	if (nb_side <= 20)
	{
		names.push_back(BASIC_POLY[nb_side - 1]);
		if (nb_side == 3)
			names.push_back("TRIANGLE");
		else if (nb_side == 4)
			names.push_back("QUADRILATERAL");
	}
	else if (nb_side < 10000000)
	{
		std::string name_1 = std::string("");
		std::string name_2 = std::string("");
		unsigned int max_loop = getNumberDigit(nb_side);
		for (int i = max_loop - 1; i >= 0; i--)
		{
			unsigned current_digit = getDigitAt(nb_side, i);
			if (current_digit != 0)
			{
				if (i == 0) 
					name_1 += "KAI";
				name_1 += PREFIX[i][current_digit - 1];
				name_2 += PREFIX[i][current_digit - 1];
			}
		}
		name_1 += "GON";
		name_2 += "GON";
		names.push_back(name_1);
		if(getDigitAt(nb_side, 0) != 0)
			names.push_back(name_2);
	}
	names.push_back(std::to_string(nb_side) + "-GON");
	return names;
}

int main()
{
	std::vector<std::string> names = getNames(120000);
	for (unsigned i = 0;i < names.size();i++)
		std::cout << names[i] << "\n";
}