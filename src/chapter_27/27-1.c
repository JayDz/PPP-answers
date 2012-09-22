/*
	chapter 27 exercise 1
	page 1033
*/
#include <stdio.h>
#include <stdlib.h>

size_t jd_strlen(const char* p)
{
	if (p == 0) return 0;

	const char* last = p;
	while (*last) last++;

	return last - p;
}

int jd_strcmp(const char* s1, const char* s2)
{
	while (*s1 == *s2 && *s1 != 0 && *s2 != 0) {
		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return 0;
	else 
	if (*s1 < *s2) 
		return -1;
	else
		return 1;
}

char* jd_strcpy(char* s1, const char* s2)
{
	int i;
	for (i = 0; *(s1 + i) = *s2++; ++i);
	return s1;
}

int main(void)
{
	const char* s1 = "Jeff";
	const char* s2 = "Jeffrey";

	//test jd_strlen()
	printf("Length of %s is %d, and the length of %s is %d.\n",
		s1,jd_strlen(s1),s2,jd_strlen(s2)); //4, 7
		
	//test jd_strcmp()
	if (jd_strcmp("dog","dog") == 0) 
		printf("dog and dog are equivalent.\n");

	if (jd_strcmp("ape","dodo") < 0)
		printf("ape comes before dodo in a dictionary.\n");
	
	if (jd_strcmp("pig","cow") > 0)
		printf("ping comes after cow in a dictionary.\n");
	
	//test jd_strcpy()
	{
		const char* s3 = "Testing jd_strcpy()";
		char* s4 = (char*) malloc(jd_strlen(s3)+1);
		jd_strcpy(s4,s3);

		printf("%s\n",s4);
		free(s4);
	}

	return 0;
}
