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
	bool playerWon = false;

	int nerdPoints = 0;

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

void PrintPlayerEndGameText(Player player);
void PrintPlayerPoints(Player player);
void PrintSymbol(char symbol, int times);

void GarbageCollector(Player player);

int StrLenght(const char* arr);

int StrLenght(const char*);
int NumberLenght(int number);


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

		if (player.isLost || player.playerWon) {
			system("CLS");
			PrintPlayerEndGameText(player);
			system("PAUSE");
			GarbageCollector(player);
			return;
		}

		PrintPlayerPoints(player);

		PrintQuestion(player, randomQuestion, numberOfQustion);

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
				continue;
			}
		case'B':
			if (player.questions[randomQuestion].answers[1].isTheRightOne)
				break;
			else {
				player.isLost = true;
				continue;
			}
		case'C':
			if (player.questions[randomQuestion].answers[2].isTheRightOne)
				break;
			else {
				player.isLost = true;
				continue;
			}
		case 'D':
			if (player.questions[randomQuestion].answers[3].isTheRightOne)
				break;
			else {
				player.isLost = true;
				continue;
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
				player.playerWon = true;
				player.nerdPoints / 2;
				continue;
			}
			else {
				cout << "Wow you suck didn't complete 1 question for real ???? \r\n";
				system("PAUSE");
				player.isLost = true;
				continue;
			}
		default:
			system("CLS");
			continue;
		}

		//If the player chose the wrong answer the game will stop. 

		system("CLS");

		numberOfQustion++;

		//After answering the current question, the question will be deleted so can't show again.
		DeletePlayerQuestion(player, randomQuestion);

		//If questions lenght hit 0 that means he answered every question and he won the game.
		if (player.questionsLenght == 0) {
			player.playerWon = true;
			continue;
		}

		//Choosing new quesiton from the array of questions.
		randomQuestion = rand() % player.questionsLenght;

		if (numberOfQustion < 5) {
			player.nerdPoints += 1000;
		}
		else if (numberOfQustion >= 5 && numberOfQustion < 10) {
			player.nerdPoints += 2500;
		}
		else {
			player.nerdPoints += 5000;
		}
	}
}

void PrintPlayerEndGameText(Player player) {
	const int QUESTION_LENGHT = 10;

	if (player.isLost) {
		cout << "You stupid donkey!!!!\r\n";
	}
	else {
		if (player.nerdPoints >= 3000 && player.nerdPoints < 5000) {
			cout << "Congrats you are not stupid as i tought :)\r\n";
		}
		else if (player.nerdPoints >= 5000 && player.nerdPoints < 10000) {
			cout << "Mhhh you are kinda neck beard\r\n";
		}
		else if (player.nerdPoints >= 10000) {
			cout << "CONGRATUALITON YOU ARE ULTIMATE NECK BEARD\r\nFind some social life mate!\r\n";
		}
		else {
			cout << "Wow you are little bit smarter than murloc!\r\n";
		}

		cout << "Nerd points: " << player.nerdPoints;

		cout << "\r\n";
	}
	
	int questionIndex = QUESTION_LENGHT - player.questionsLenght;

	if (questionIndex > 0) {
		cout << "You end at question " << questionIndex;
	}
	cout << "\r\n";
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

void PrintPlayerPoints(Player player) {

	const int JOKER_LENGHT = 13;
	const int RECTANGLE_WIDTH = 50;
	const int RECTANGLE_HEIGHT = 9;

	char joker[JOKER_LENGHT] = { "Joker: " };
	char intro[] = { "Welcome to \"BECOME A NERD\" !!!!" };
	char balance[] = { "Nerd points: " };

	int jokerLenght = StrLenght(joker);
	int balanceLenght = StrLenght(balance);

	if (player.isJokerUsed) {
		joker[jokerLenght] = 'N';
		joker[jokerLenght + 1] = 'o';
		joker[jokerLenght + 2] = '\0';
		jokerLenght = StrLenght(joker);
	}
	else {
		joker[jokerLenght] = 'Y';
		joker[jokerLenght + 1] = 'e';
		joker[jokerLenght + 2] = 's';
		joker[jokerLenght + 3] = '\0';
		jokerLenght = StrLenght(joker);
	}

	for (int i = 0; i < RECTANGLE_WIDTH; i++)
	{
		cout << "*";
	}

	cout << "\r\n*";
	PrintSymbol(' ', RECTANGLE_WIDTH - 2);
	cout << "*\r\n";

	cout << "*  ";

	int introLenght = StrLenght(intro);

	for (int i = 0; i < introLenght; i++)
	{
		cout << intro[i];
	}
	PrintSymbol(' ', RECTANGLE_WIDTH - 4 - introLenght);
	cout << "*\r\n";

	for (int i = 2; i < RECTANGLE_HEIGHT - 2; i++)
	{
		if (i == (((RECTANGLE_HEIGHT - 2) / 2) - 1)) {
			cout << "*  ";

			for (int i = 0; i < jokerLenght; i++)
			{
				cout << joker[i];
			}
			PrintSymbol(' ', RECTANGLE_WIDTH - 4 - jokerLenght);
			cout << "*\r\n";
		}
		else if (i == ((RECTANGLE_HEIGHT - 2) / 2) + 1) {
			cout << "*  ";

			for (int i = 0; i < balanceLenght; i++)
			{
				cout << balance[i];
			}
			cout << player.nerdPoints;
			PrintSymbol(' ', RECTANGLE_WIDTH - 5 - NumberLenght(player.nerdPoints) - balanceLenght);
			cout << "*\r\n";
		}
		else {
			cout << "*";
			PrintSymbol(' ', RECTANGLE_WIDTH - 2);
			cout << "*\r\n";
		}
	}

	for (int i = 0; i < RECTANGLE_WIDTH; i++)
	{
		cout << "*";
	}
	cout << "\r\n";
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
	
	delete[] player.questions->answers;

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

int NumberLenght(int number) {

	int counter = 0;

	while (number != 0) {
		counter++;
		number /= 10;
	}

	return counter;
}

void PrintSymbol(char symbol, int times) {
	for (int i = 0; i < times; i++)
	{
		cout << symbol;
	}

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

void GarbageCollector(Player player) {
	for (int i = 0; i < player.questionsLenght; i++)
	{
		delete[] player.questions[i].answers;
	}

	delete[] player.questions;
}