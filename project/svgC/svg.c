#include <stdio.h>
int main(){
char* header = "<svg version=\"1.1\"baseProfile=\"full\"xmlns=\"http://www.w3.org/2000/svg\"xmlns:xlink=\"http://www.w3.org/1999/xlink\"xmlns:ev=\"http://www.w3.org/2001/xml-events\">";
char* html = " <html>\
<body>  \
<h1>My first SVG</h1> \
<svg width=\"100\" height=\"100\"> \
  <circle cx=\"50\" cy=\"50\" r=\"40\" stroke=\"green\" stroke-width=\"4\" fill=\"yellow\" /> \ 
</svg> \
</body> \
</html>  ";
FILE *fp;
fp = fopen("borek.html","w");
fputs(html,fp);
// fputs(header,fp);
fclose(fp);
}