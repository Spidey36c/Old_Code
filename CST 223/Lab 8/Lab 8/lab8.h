#ifdef LAB8_CODE
#define LAB8_CODE

#define LAB8_A
template<typename str, typename obj> str act1(str string, obj object) { return object.action(string); };
#endif

#ifdef LAB8_CODE
#define LAB8_CODE
#define LAB8_B
template<typename str, typename obj, typename obj2> str act1(str string, obj object1, obj2 object2) { return object2.action(object1.action(string)); };

#endif

#ifdef LAB8_CODE
#define LAB8_CODE
#define LAB8_C
template<typename T, typename obj> void pipeline(T &string, obj object) { object.action(string); };

template<typename T, typename obj, typename...objArgs> 
void pipeline(T &s, obj object, objArgs... args) 
{ 
	object.action(s); 
	pipeline(s, args...);
};
#endif

#ifdef LAB8_CODE
#define LAB8_CODE
#define LAB8_D

template<typename T, typename... instA> 
void vm(T &reg,instA... instructions)
{
	constexpr size_t n = sizeof...(instructions);
	int pc = reg.getPC();


	while (pc >= 0 && pc < n);
}

#endif
