#include <iostream>
#include <time.h>
using namespace std;
struct Answer {
	const char* answer;

	bool isTheRightOne = false;
};

struct Question {
	const char* question;

	int answersLenght = 4;

	Answer* answers = new Answer[4];
};

struct Player {
	bool isJokerUsed = false;

	bool isLost = false;

	int questionsLenght = 10;

	Question* questions = new Question[10];
};

void StartEngine(bool);

void deleteQuestion(Player&, int);
void GenerateQuestionsForPlayer(Player& player);
void PrintAnswers(Player& player, int indexOfAnswer);
void LeaveOneFakeAnswer(Player player, int questionIndex);
void PrintQuestion(Player& player, int index, int numberOfQuestion);
void deleteAnswer(Player& player, int questionIndex, int answerIndex);

int StrLenght(const char*);

int main() {
	char command = ' ';

	while (true) {
		cout << "Type 'S' to start the game.\r\n";
		cout << "Type 'E' to exit.\r\n";

		cin >> command;

		if (command == 'S') {
			system("CLS");
			StartEngine(true);
		}
		else if (command == 'E') {
			return 0;
		}
		else {
			cout << "\r\nInvalid command\r\n\r\n";
		}
	}

	return 0;
}

void StartEngine(bool isStarted) {
	srand(time(NULL));

	Player player;

	GenerateQuestionsForPlayer(player);

	int numberOfQustion = 1;

	int randomQuestion = rand() % player.questionsLenght;

	while (isStarted) {
		char command = ' ';

		PrintQuestion(player, randomQuestion, numberOfQustion);

		cout << "50/50: ";
		if (player.isJokerUsed) {
			cout << "true\r\n";
		}
		else {
			cout << "false\r\n";
		}

		if (!player.isJokerUsed) {
			cout << "To use the joker type 'J'\r\n";
		}

		cout << "You can exit the game in any time by typing 'E'.\r\n";

		cout << "Enter your choise: "; cin >> command;

		switch (command) {
		case 'A':
			if (player.questions[randomQuestion].answers[0].isTheRightOne)
				break;
			else {
				player.isLost = true;
				break;
			}
		case'B':
			if (player.questions[randomQuestion].answers[1].isTheRightOne)
				break;
			else {
				player.isLost = true;
				break;
			}
		case'C':
			if (player.questions[randomQuestion].answers[2].isTheRightOne)
				break;
			else {
				player.isLost = true;
				break;
			}
		case 'D':
			if (player.questions[randomQuestion].answers[3].isTheRightOne)
				break;
			else {
				player.isLost = true;
				break;
			}
		case'J':
			system("CLS");
			if (!player.isJokerUsed) {
				player.isJokerUsed = true;
				LeaveOneFakeAnswer(player, randomQuestion);
			}
			continue;
		case'E':

			system("CLS");

			if (numberOfQustion > 1) {

				cout << "Congrats you did " << numberOfQustion << " questions.";
				return;
			}
			else {
				continue;
			}
		default:
			system("CLS");
			continue;
		}

		if (player.isLost) {
			cout << "You lost better next time :)!";
			return;
		}

		system("CLS");

		numberOfQustion++;

		deleteQuestion(player, randomQuestion);

		if (player.questionsLenght == 0) {
			cout << "Congrats you won !!!!!\r\n";
			return;
		}

		randomQuestion = rand() % player.questionsLenght;
	}
}


void PrintQuestion(Player& player, int index, int numberOfQuestion) {

	cout << numberOfQuestion << ". " << player.questions[index].question << "\r\n\r\n";

	PrintAnswers(player, index);

	cout << "\r\n\r\n";
}

void PrintAnswers(Player& player, int indexOfQuestion) {
	char symbolOfAnswer = 'A';

	for (int i = 0; i < player.questions[indexOfQuestion].answersLenght; i++)
	{
		cout << symbolOfAnswer << ". " << player.questions[indexOfQuestion].answers[i].answer;

		if ((i + 1) % 2 == 0) {
			cout << "\r\n";
		}
		else {
			cout << "		";
		}

		symbolOfAnswer++;
	}
}

void LeaveOneFakeAnswer(Player player, int questionIndex) {
	Question& question = player.questions[questionIndex];

	while (question.answersLenght > 2) {
		int randAnswer = rand() % question.answersLenght;

		if (!question.answers[randAnswer].isTheRightOne) {
			deleteAnswer(player, questionIndex, randAnswer);
		}
	}
}

void deleteQuestion(Player& player, int index) {
	for (int i = index; i < player.questionsLenght - 1; i++)
	{
		player.questions[i] = player.questions[i + 1];
	}

	player.questionsLenght--;
}

void deleteAnswer(Player& player, int questionIndex, int answerIndex) {
	for (int i = answerIndex; i < player.questions[questionIndex].answersLenght - 1; i++)
	{
		player.questions[questionIndex].answers[i] = player.questions[questionIndex].answers[i + 1];
	}

	player.questions[questionIndex].answersLenght--;
}

int StrLenght(const char* arr) {
	int index = 0;

	while (arr[index++] != '\0');

	return index - 1;
}

void GenerateQuestionsForPlayer(Player& player) {
	const char** questions = new const char* [10]{
	"What is the original name given to the blood elves?"
	, "Dalaran once rested in Silverpine Forest before being transported to Northrend"
	,"The Four Horsemen consist of which four bosses during the Naxxramas raid?"
	,"The curse of flesh was the cause behind the creation of the dwarves"
	,"Onyxia used to spy on  Stormwind in  the guise of a chief advisor. What did she call herself while under her human form"
	,"Which of the following is the only raid in world of warcraft where you can play a game of  chess?"
	,"Doom is coming is it not?"
	,"What was the purpose of the blood elven expedition in bloodmist isle?"
	,"Which of these quotes is NOT spoken by Onyxia in the raid \'Onyxia\'s Lair\'"
	,"The most annoying boss in the game because of the fact that he says quotes in an insane, whiny and nasal voice is most definately..." };

	const char** answers = new const char* [40]{
	"Sin\'dorei",
	"Quil\'dorei",
	"Kel\'dorei",
	"Quel\'dorei",

	"False",
	"True",
	"Maybe",
	"Your Mum",

	"Thane Korth azz, Lady Blauemox, Baron Rivendare and Sir Zeliek",
	"Lady Blauemox, Darion Mograine, Lord Malakriez and Teron Gorefiend",
	"Baron Rivendare, Darion Mograine, Teron Gorefiend and Scourgelord Tyrannus",
	"Teron Gorefiend, Sir Zeliek, Lord Malakriez and Lady Blauemox",

	"True",
	"False",
	"Pineaple",
	"ApplePen",

	"Lady Katrana Prestor",
	"Lady Katirina Preston",
	"Magistrix Lauville Karnos",
	"Magistrix Lauville Karnor",

	"Karazhan",
	"The Steamvaults",
	"The Gamevaults",
	"Boardgame Land",

	"DOOOOOOOOOOOOOOOOOOOOOOOOOOOOM",
	"E+1=12",
	"I guess you could say that..",
	"What does this have to do with Wow?",

	"To create a portal to Outland so they could travel through it.",
	"To assassinate the draenei leader.",
	"To summon an army of demons to overwhelm the Exodar.",
	"To go sightseeing.",

	"Arrogant fools, I shall enjoy feasting upon your charred flesh!",
	"\'I am tired of this meaningless exertion! I shall incinerate you all from above!\'",
	"\'How fortuitous, normally i have to leave my lair in order to feed!\'",
	"\'Whelps, many whelps! NOW, handle it!!!\'",

	"Interrigator Vishas",
	"Your Mum",
	"Defias Underlord Kash",
	"Your uncle who is an engineer",
	};

	for (int i = 0; i < 10; i++)
	{
		player.questions[i].question = questions[i];
		player.questions[i].answers[0].answer = answers[i * 4];
		player.questions[i].answers[0].isTheRightOne = true;

		for (int j = 1; j < 4; j++)
		{
			int currentFakeAnswer = i * 4 + j;

			player.questions[i].answers[j].answer = answers[currentFakeAnswer];
		}

	}

}