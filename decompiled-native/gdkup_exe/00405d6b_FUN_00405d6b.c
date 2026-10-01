// 00405d6b FUN_00405d6b [Global]
// program: gdkup.exe

char * FUN_00405d6b(void)

{
  int in_EAX;
  char *pcVar1;
  
  pcVar1 = (char *)**(undefined4 **)(in_EAX + 0x14);
  if (*pcVar1 == '\x02') {
    pcVar1 = *(char **)(pcVar1 + 1);
  }
  return pcVar1;
}


