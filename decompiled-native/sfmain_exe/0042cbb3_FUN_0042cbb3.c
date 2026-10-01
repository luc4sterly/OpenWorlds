// 0042cbb3 FUN_0042cbb3 [Global]
// program: sfmain.exe

void __fastcall FUN_0042cbb3(undefined4 param_1,char param_2)

{
  char cVar1;
  char *in_EAX;
  
  do {
    if (param_2 == *in_EAX) {
      return;
    }
    cVar1 = *in_EAX;
    in_EAX = in_EAX + 1;
  } while (cVar1 != '\0');
  return;
}


