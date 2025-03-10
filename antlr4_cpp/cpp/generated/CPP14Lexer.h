
// Generated from CPP14.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  CPP14Lexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, MultiLineMacro = 7, 
    Directive = 8, Alignas = 9, Alignof = 10, Asm = 11, Auto = 12, Bool = 13, 
    Break = 14, Case = 15, Catch = 16, Char = 17, Char16 = 18, Char32 = 19, 
    Class = 20, Const = 21, Constexpr = 22, Const_cast = 23, Continue = 24, 
    Decltype = 25, Default = 26, Delete = 27, Do = 28, Double = 29, Dynamic_cast = 30, 
    Else = 31, Enum = 32, Explicit = 33, Export = 34, Extern = 35, False = 36, 
    Final = 37, Float = 38, For = 39, Friend = 40, Goto = 41, If = 42, Inline = 43, 
    Int = 44, Long = 45, Mutable = 46, Namespace = 47, New = 48, Noexcept = 49, 
    Nullptr = 50, Operator = 51, Override = 52, Private = 53, Protected = 54, 
    Public = 55, Register = 56, Reinterpret_cast = 57, Return = 58, Short = 59, 
    Signed = 60, Sizeof = 61, Static = 62, Static_assert = 63, Static_cast = 64, 
    Struct = 65, Switch = 66, Template = 67, This = 68, Thread_local = 69, 
    Throw = 70, True = 71, Try = 72, Typedef = 73, Typeid_ = 74, Typename_ = 75, 
    Union = 76, Unsigned = 77, Using = 78, Virtual = 79, Void = 80, Volatile = 81, 
    Wchar = 82, While = 83, LeftParen = 84, RightParen = 85, LeftBracket = 86, 
    RightBracket = 87, LeftBrace = 88, RightBrace = 89, Plus = 90, Minus = 91, 
    Star = 92, Div = 93, Mod = 94, Caret = 95, And = 96, Or = 97, Tilde = 98, 
    Not = 99, Assign = 100, Less = 101, Greater = 102, PlusAssign = 103, 
    MinusAssign = 104, StarAssign = 105, DivAssign = 106, ModAssign = 107, 
    XorAssign = 108, AndAssign = 109, OrAssign = 110, LeftShift = 111, RightShift = 112, 
    LeftShiftAssign = 113, RightShiftAssign = 114, Equal = 115, NotEqual = 116, 
    LessEqual = 117, GreaterEqual = 118, AndAnd = 119, OrOr = 120, PlusPlus = 121, 
    MinusMinus = 122, Comma = 123, ArrowStar = 124, Arrow = 125, Question = 126, 
    Colon = 127, Doublecolon = 128, Semi = 129, Dot = 130, DotStar = 131, 
    Ellipsis = 132, Identifier = 133, Integerliteral = 134, Decimalliteral = 135, 
    Octalliteral = 136, Hexadecimalliteral = 137, Binaryliteral = 138, Integersuffix = 139, 
    Characterliteral = 140, Floatingliteral = 141, Stringliteral = 142, 
    Userdefinedintegerliteral = 143, Userdefinedfloatingliteral = 144, Userdefinedstringliteral = 145, 
    Userdefinedcharacterliteral = 146, Whitespace = 147, Newline = 148, 
    BlockComment = 149, LineComment = 150
  };

  CPP14Lexer(antlr4::CharStream *input);
  ~CPP14Lexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

