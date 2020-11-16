#include <iostream>
#include <string>
#include <bitset>

using namespace std;

typedef const std::string& StringPiece;

void StringToBinary(const std::string& s) {    
	std::cout << "s=" << s << std::endl;    
	std::cout << "s.size=" << s.size() << std::endl;    
	for (std::size_t i = 0; i < s.size(); ++i) {    
		std::cout << std::bitset<8>(s.c_str()[i]) << " ";    
	}    
	std::cout << std::endl;    
}

static inline size_t CEscapedLength(StringPiece src) {
	static char c_escaped_len[256] = {
		4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 4, 4, 2, 4, 4,  // \t, \n, \r
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1,  // ", '
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // '0'..'9'
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // 'A'..'O'
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1,  // 'P'..'Z', '\'
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // 'a'..'o'
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4,  // 'p'..'z', DEL
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	};

	size_t escaped_len = 0;
	for (int i = 0; i < src.size(); ++i) {
		unsigned char c = static_cast<unsigned char>(src[i]);
		escaped_len += c_escaped_len[c];
	}
	return escaped_len;
}

void CEscapeAndAppend(StringPiece src, std::string *dest) {
	size_t escaped_len = CEscapedLength(src);
	if (escaped_len == src.size()) {
		dest->append(src.data(), src.size());
		return;
	}

	size_t cur_dest_len = dest->size();
	dest->resize(cur_dest_len + escaped_len);
	char* append_ptr = &(*dest)[cur_dest_len];

	for (int i = 0; i < src.size(); ++i) {
		unsigned char c = static_cast<unsigned char>(src[i]);
		std::cout << "i=" << i << ",c=" << c << std::endl;
		switch (c) {
			case '\n': *append_ptr++ = '\\'; *append_ptr++ = 'n'; break;
			case '\r': *append_ptr++ = '\\'; *append_ptr++ = 'r'; break;
			case '\t': *append_ptr++ = '\\'; *append_ptr++ = 't'; break;
			case '\"': *append_ptr++ = '\\'; *append_ptr++ = '\"'; break;
			case '\'': *append_ptr++ = '\\'; *append_ptr++ = '\''; break;
			case '\\': *append_ptr++ = '\\'; *append_ptr++ = '\\'; break;
			default:
					   if (!isprint(c)) {
						   *append_ptr++ = '\\';
						   *append_ptr++ = '0' + c / 64;
						   *append_ptr++ = '0' + (c % 64) / 8;
						   *append_ptr++ = '0' + c % 8;
					   } else {
						   *append_ptr++ = c;
					   }
					   break;
		}
	}
}



int main() {
	std::string str1 = "\346\234\211\344\272\272\345\220\227\x7E";
	// str1 = "asdfasdf\n";
	StringToBinary(str1);
	for (auto s : str1) {
		std::cout << s;
	}
	std::cout << "=========" << std::endl;
	std::string str2 = "";
	CEscapeAndAppend(str1, &str2);
	std::cout << "str1=" << str1 << std::endl;
	std::cout << "str2=" << str2 << std::endl;
}
