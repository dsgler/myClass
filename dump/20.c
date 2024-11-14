#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1024
#define WORD_SIZE 128

int main()
{
    char buffer[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];

    FILE *fp = fopen("./a.txt", "r");

    char raw[WORD_SIZE];
    char rsp[WORD_SIZE];

    scanf("%s %s", raw, rsp);

    int rawLen = strlen(raw);
    int rspLen = strlen(rsp);

    int cnt = 0;
    while (!feof(fp))
    {
        fgets(buffer, BUFFER_SIZE, fp);

        char word[WORD_SIZE];
        int bufferLen = strlen(buffer);
        int pBuffer = 0;
        int pBuffer2 = 0;
        int pWord = 0;

        for (; pBuffer < bufferLen; pBuffer++)
        {
            char ch = buffer[pBuffer];
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            {
                word[pWord++] = ch;
            }
            else
            {
                if (pWord != 0)
                {
                    word[pWord] = '\0';

                    if (pWord<rawLen){
                        for (int i = 0; i < pWord; i++)
                        {
                            buffer2[pBuffer2++] = word[i];
                        }
                    }else{
                        int front=0;
                        for (;front<=pWord-rawLen;front++){
                            if (strncmp(raw,word+front,rawLen)==0){
                                cnt++;
                                for (int i = 0; i < rspLen; i++)
                                {
                                    buffer2[pBuffer2++] = rsp[i];
                                }
                                front=front+rawLen;
                                break;
                            }else{
                                buffer2[pBuffer2++] = word[front];
                            }
                        }
                        //善后
                        for (;front<pWord;front++){
                            buffer2[pBuffer2++] = word[front];
                        }
                    }
                    // if (strncmp(raw,word,rawLen)==0)
                    // {
                    //     for (int i = 0; i < rspLen; i++)
                    //     {
                    //         buffer2[pBuffer2++] = rsp[i];
                    //     }
                    //     cnt++;
                    //     for (int i = rawLen; i < pWord; i++)
                    //     {
                    //         buffer2[pBuffer2++] = word[i];
                    //     }
                    // }
                    // else
                    // {
                    //     for (int i = 0; i < pWord; i++)
                    //     {
                    //         buffer2[pBuffer2++] = word[i];
                    //     }
                    // }
                    pWord = 0;
                }

                buffer2[pBuffer2++] = ch;
            }
        }
        buffer2[pBuffer2] = '\0';
        printf("%d\n", cnt);
        printf("%s", buffer2);
    }
}