#include <stdio.h>
#include <stdlib.h>

char input[50];
char stack[50];
int top = -1;
int ip = 0;

void push(char c)
{
stack[++top] = c;
}

void pop()
{
top--;
}

void error()
{
printf("\nSyntax Error\n");
exit(0);
}

void display()
{
int i;

printf("\n");

for(i=0;i<=top;i++)
printf("%c",stack[i]);

printf("\t\t");

for(i=ip;input[i]!='\0';i++)
printf("%c",input[i]);
}

int main()
{
printf("Enter string ending with $ : ");
scanf("%s",input);

push('0');

printf("\nSTACK\t\tINPUT");
printf("\n-------------------------");

while(1)
{
display();

switch(stack[top])
{
case '0':

if(input[ip]=='a')
{
ip++;
push('a');
push('2');
}
else if(input[ip]=='b')
{
ip++;
push('b');
push('3');
}
else
error();

break;

case '1':

if(input[ip]=='$')
{
printf("\n\nString Accepted\n");
return 0;
}
else
error();

break;

case '2':

if(input[ip]=='a')
{
ip++;
push('a');
push('2');
}
else if(input[ip]=='b')
{
ip++;
push('b');
push('3');
}
else
error();

break;

case '3': /* Reduce S->b */

if(input[ip]=='$')
{
pop(); /* state 3 */
pop(); /* b */

push('S');

if(stack[top-1]=='0')
push('1');
else if(stack[top-1]=='2')
push('4');
else
error();
}
else
error();

break;

case '4': /* Reduce S->aS */

if(input[ip]=='$')
{
pop(); /* state 4 */
pop(); /* S */
pop(); /* state 2 */
pop(); /* a */

push('S');

if(stack[top-1]=='0')
push('1');
else if(stack[top-1]=='2')
push('4');
else
error();
}
else
error();

break;

default:
error();
}
}

return 0;
}
