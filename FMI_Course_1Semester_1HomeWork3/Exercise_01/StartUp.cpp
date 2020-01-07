#include <iostream>
#include <time.h>
using namespace std;

struct Answer {
	const char* answer = new char[1];

	bool isTheRightOne = false;
};

struct Question {
	const char* question = new char[1];

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

void GenerateQuestionsForPlayer(Player& player);

void ShuffleTheAnswersOfQuestion(Question& question);

void PrintAnswers(Question question);
void PrintQuestion(Player player, int index, int numberOfQuestion);

void DeletePlayerQuestion(Player&, int);
void DeletePlayerAnswer(Player& player, int questionIndex, int answerIndex);

void LeaveOneFakeAnswer(Player& player, int questionIndex);

void DeleteElement(char* arr, int deleteIndex, int numLenght);

int StrLenght(const char*);

int main() {
	char command = ' ';

	while (true) {
		system("CLS");

		cout << "Type 'S' to start the game.\r\n";
		cout << "Type 'E' to exit.\r\n";

		cin >> command;

		//Depends of the char which is entered will start the game or exit if the input is wrong will make you to enter new symbol.
	
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
			cout << "It's used\r\n";
		}
		else {
			cout << "It's not used\r\n";
		}

		if (!player.isJokerUsed) {
			cout << "To use the joker type 'J'\r\n";
		}

		cout << "You can exit the game in any time by typing 'E'.\r\n";

		cout << "Enter your choise: "; cin >> command;

		//With A,B,C,D the player is chosing which answer is the right one if he enter wrong one the game will stop if the enter right one will continue.
		//The player can exit with entering 'E' at any time if he wants to.
		//The player with J can use 50/50 the purpose of the 50/50 is to remove 2 of the wrong answers.

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

				cout << "Congrats you did " << numberOfQustion - 1 << " questions. \r\n";
				system("PAUSE");
				return;
			}
			else {
				cout << "Wow you suck didn't complete 1 question for real ???? \r\n";
				system("PAUSE");
				return;
			}
		default:
			system("CLS");
			continue;
		}

		//If the player chose the wrong answer the game will stop. 
		if (player.isLost) {
			cout << "You lost at question: " << numberOfQustion << " better luck next time :)!\r\n";
			system("PAUSE");
			return;
		}

		system("CLS");

		numberOfQustion++;

		//After answering the current question, the question will be deleted so can't show again.
		DeletePlayerQuestion(player, randomQuestion);

		//If questions lenght hit 0 that means he answered every question and he won the game.
		if (player.questionsLenght == 0) {
			cout << "Congrats you won !!!!!\r\n\r\n";
			system("PAUSE");
			return;
		}

		//Choosing new quesiton from the array of questions.
		randomQuestion = rand() % player.questionsLenght;
	}
}


void PrintQuestion(Player player, int index, int numberOfQuestion) {

	cout << numberOfQuestion << ". " << player.questions[index].question << "\r\n\r\n";

	PrintAnswers(player.questions[index]);

	cout << "\r\n\r\n";
}

void PrintAnswers(Question question) {
	char symbolOfAnswer = 'A';

	for (int i = 0; i < question.answersLenght; i++)
	{
		cout << symbolOfAnswer << ". " << question.answers[i].answer;

		if ((i + 1) % 2 == 0) {
			cout << "\r\n";
		}
		else {
			cout << "		";
		}

		symbolOfAnswer++;
	}
}

void LeaveOneFakeAnswer(Player& player, int questionIndex) {
	Question& question = player.questions[questionIndex];

	//Deleting answers until the lenght of the answers hit 2. in that case only the right one and one wrong will be left.
	while (question.answersLenght > 2) {
		int randAnswer = rand() % question.answersLenght;

		//Deleting the answer only if is a wrong one
		if (!question.answers[randAnswer].isTheRightOne) {
			DeletePlayerAnswer(player, questionIndex, randAnswer);
		}
	}
}

void DeletePlayerQuestion(Player& player, int index) {
	for (int i = index; i < player.questionsLenght - 1; i++)
	{
		player.questions[i] = player.questions[i + 1];
	}

	player.questionsLenght--;
}

void DeletePlayerAnswer(Player& player, int questionIndex, int answerIndex) {
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

	const int ANSWERS_LENGHT = 4;
	const int QUESTUONS_LENGHT = 10;

	//Library for question and answers 
	//Every 4 answers are for 1 question and they are sorted for every specific question from the questions array.

	const char** questions = new const char* [QUESTUONS_LENGHT] {
		"What is the original name given to the blood elves?"
			, "Dalaran once rested in Silverpine Forest before being transported to Northrend"
			, "The Four Horsemen consist of which four bosses during the Naxxramas raid?"
			, "The curse of flesh was the cause behind the creation of the dwarves"
			, "Onyxia used to spy on  Stormwind in  the guise of a chief advisor. What did she call herself while under her human form"
			, "Which of the following is the only raid in world of warcraft where you can play a game of  chess?"
			, "Doom is coming is it not?"
			, "What was the purpose of the blood elven expedition in bloodmist isle?"
			, "Which of these quotes is NOT spoken by Onyxia in the raid \'Onyxia\'s Lair\'"
			, "The most annoying boss in the game because of the fact that he says quotes in an insane, whiny and nasal voice is most definately..." };

	const char** answers = new const char* [ANSWERS_LENGHT * 10]{
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


	//Adding the questions with there answers to the player.
	for (int i = 0; i < QUESTUONS_LENGHT; i++)
	{

		//Every first answer for every question is the right one.
		Question& currentQuestion = player.questions[i];
		currentQuestion.question = questions[i];
		currentQuestion.answers[0].answer = answers[i * ANSWERS_LENGHT];
		currentQuestion.answers[0].isTheRightOne = true;

		//Adding the false answers.
		for (int j = 1; j < ANSWERS_LENGHT; j++)
		{
			int currentFakeAnswer = i * ANSWERS_LENGHT + j;

			currentQuestion.answers[j].answer = answers[currentFakeAnswer];
		}

		//Shuffle all answers.
		ShuffleTheAnswersOfQuestion(currentQuestion);

	}

}

void ShuffleTheAnswersOfQuestion(Question& question) {

	const int ANSWERS_LENGHT = 4;

	int howManyTimesToSwap = rand() % 10;

	//Chosing random number for how many times to swap the answers
	for (int i = 0; i < howManyTimesToSwap; i++)
	{
		//Chosing random index to swap the current answers with another.
		int randSwap = rand() % (ANSWERS_LENGHT - 1);
		swap(question.answers[i % (ANSWERS_LENGHT - 1)], question.answers[randSwap]);
	}
}