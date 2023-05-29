#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;
class clsString
{
private:
	string _Value = "";
public:
	clsString() {
		_Value = "";
	};
	clsString(string Value) {
		_Value = Value;
	};
	string getValue() {
		return _Value;
	};
	void setValue(string Value) {
		_Value = Value;
	};
	static short countWords(string s) {
		char delimtor = ' ';
		short count = 0, slicer = 0;
		string word = "";
		s = s + delimtor;
		while (s.find(delimtor) != s.npos) {
			slicer = s.find(delimtor);
			word = s.substr(0, slicer);
			s = s.substr(slicer + 1, s.length());
			if (word != "" && word != " ")
				count++;
		}
		return count;
	};
	short countWords() {
		return countWords(_Value);
	};
	static string capitalization(string statement) {
		for (int i = 0;i < statement.length();i++) {
			if (statement[i] != ' ') {
				statement[i] = toupper(statement[i]);
			}
		}
		return statement;
	};
	string capitalization() {
		return capitalization(_Value);
	};
	static string smallization(string statement) {
		for (int i = 0;i < statement.length();i++) {
			if (statement[i] != ' ') {
				statement[i] = tolower(statement[i]);
			}
		}
		return statement;
	};
	string smallization() {
		return smallization(_Value);
	};
	static string replace(string fullStatement, string oldPart, string newPart) {
		short fromIndex = fullStatement.find(oldPart);
		return fullStatement.replace(fromIndex, oldPart.length(), newPart);
	};
	string replace(string oldPart, string newPart) {
		return replace(_Value, oldPart, newPart);
	};
	static vector<string> split(string s, string delimiter = " ") {
		vector<string> words;
		int currentIndex = 0;
		string word = "";
		s = s + delimiter;
		while ((currentIndex = s.find(delimiter)) != s.npos) {
			word = s.substr(0, currentIndex);
			s.erase(0, currentIndex + delimiter.length());
			if (word != "" && word != delimiter)
				words.push_back(word);
		}
		return words;
	};
	vector<string> split(string delimiter = " ") {
		return split(_Value, delimiter);
	};
	static string findWordFirstLetter(string statement) {
		bool isFirstLetter = true;
		string result = "";
		for (int i = 0;i < statement.length();i++) {
			if (isFirstLetter && statement[i] != ' ') {
				result = result + statement[i];
			}
			isFirstLetter = (statement[i] == ' ' ? true : false);
		}
		return result;
	};
	string findWordFirstLetter() {
		return findWordFirstLetter(_Value);
	}
	static void trimRight(string& s) {
		for (short i = s.length() - 1;i >= 0;i--) {
			if (s[i] != ' ') {
				s = s.substr(0, i + 1);
				break;
			}
		}
	}
	static void trimLeft(string& s) {
		for (short i = 0;i < s.length();i++) {
			if (s[i] != ' ') {
				s = s.substr(i, s.length() - 1);
				break;
			}
		}
	}
	static string trim(string s) {
		trimLeft(s);
		trimRight(s);
		return s;
	}
	string trim() {
		return trim(_Value);
	}
	static string uppercase(string statement) {
		bool isFirstLetter = true;
		for (int i = 0;i < statement.length();i++) {
			if (isFirstLetter && statement[i] != ' ') {
				statement[i] = toupper(statement[i]);
			}
			isFirstLetter = (statement[i] == ' ' ? true : false);
		}
		return statement;
	};
	string uppercase() {
		return uppercase(_Value);
	};
	static string lowercase(string statement) {
		bool isFirstLetter = true;
		for (int i = 0;i < statement.length();i++) {
			if (isFirstLetter && statement[i] != ' ') {
				statement[i] = tolower(statement[i]);
			}
			isFirstLetter = (statement[i] == ' ' ? true : false);
		}
		return statement;
	};
	string lowercase() {
		return lowercase(_Value);
	};
	static char invertCaseLetter(char letter) {
		if (islower(letter))
			letter = toupper(letter);
		else
			letter = tolower(letter);

		return letter;
	}
	static string invertAllLetters(string s) {
		for (int i = 0;i < s.length();i++) {
			s[i] = invertCaseLetter(s[i]);
		}
		return s;
	}
	string invertAllLetters() {
		return invertAllLetters(_Value);
	}
	static short countSpecificLetter(string s, char target) {
		short count = 0;
		for (short i = 0;i < s.length();i++) {
			if (target == s[i]) count++;
		}
		return count;
	};
	short countSpecificLetter(char target) {
		return countSpecificLetter(_Value, target);
	};
	static bool isVowel(char& letter) {
		letter = tolower(letter);
		return (letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'o') || (letter == 'u');
	};
	static short countVowels(string s) {
		short count = 0;
		for (short i = 0; i < s.length();i++) {
			if (isVowel(s[i])) count++;
		}
		return count;
	};
	short countVowels() {
		return countVowels(_Value);
	};
	static string join(vector<string>& words, string delimiter = " ") {
		string result;
		for (string& word : words) {
			result = result + delimiter + word;
		}
		return result.substr(delimiter.length(), result.length() - 1);
	}
	static string reverseString(string& s) {
		vector<string>words;
		words = split(s, " ");
		short counter = 0, reverseCounter = words.size() - 1;
		string temp;
		for (;counter < reverseCounter;counter++, reverseCounter--) {
			temp = words.at(counter);
			words.at(counter) = words.at(reverseCounter);
			words.at(reverseCounter) = temp;
		}
		return join(words, " ");
	};
	string reverseString() {
		return reverseString(_Value);
	};
	static string removePunctuations(string s) {
		string punc = ",;.:!?\"\'()", result = "";
		for (short i = 0;i < s.length();i++) {
			if (!ispunct(s[i])) {
				result = result + s[i];
			}
		}
		return result;
	};
	void removePunctuations() {
		_Value= removePunctuations(_Value);
	}
};
