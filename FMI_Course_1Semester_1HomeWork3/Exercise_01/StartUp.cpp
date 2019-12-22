struct Answer {
	bool isTheRightOne = false;

	char* answer;
};

struct Question {
	char* question;

	Answer answers[4];
};

struct Player {
	bool isJokerUsed = false;

	bool isLost = false;

	Question* questions;
};

int main() {

	return 0;
}