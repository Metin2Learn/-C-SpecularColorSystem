// Sub else if (*cur == L'h') // end of hyperlink
//Atentie, sa fie dupa cel cu "h", nu cu "H"


// Adauga:

    else if (*cur == L'E') // emoji |Epath/emo|e
    {
        tagLen = 2;
        return TEXT_TAG_EMOJI_START;
    }
    else if (*cur == L'e') // end of emoji
    {
        tagLen = 2;
        return TEXT_TAG_EMOJI_END;
    }
	
	
// Mai jos, ai primul else if (tag == TEXT_TAG_HYPERLINK_END)
// Adauga sub el:

        else if (tag == TEXT_TAG_EMOJI_START)
            hyperlinkStep = 1;
        else if (tag == TEXT_TAG_EMOJI_END)
            hyperlinkStep = 0;
		
		
// Mai jos, inca un else if (tag == TEXT_TAG_HYPERLINK_END)
// Adauga sub el:

        else if (tag == TEXT_TAG_EMOJI_START)
            hyperlinkStep = 1;
        else if (tag == TEXT_TAG_EMOJI_END)
            hyperlinkStep = 0;
		
		
// Mai jos, inca un else if (tag == TEXT_TAG_HYPERLINK_END)
// Adauga sub el:

        else if (tag == TEXT_TAG_EMOJI_START)
            hyperlinkStep = 1;
        else if (tag == TEXT_TAG_EMOJI_END)
            hyperlinkStep = 0;