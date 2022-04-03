#pragma once
#include<string>
#include "word_card.h"
#include"bidirectional_list_on_array.h"
#include <map>

class Vocabulary {
public:
	void ReadFileToCards(std::string file_path);
	WordCard* ConvertStringToWordCard(string str);
	void MakeFrequencyVocab();
	void SortWords();
	std::map<string, size_t> CopyToMap();

private:
	BiDirectionalListOnArray<WordCard*> list_word_cards;

};

