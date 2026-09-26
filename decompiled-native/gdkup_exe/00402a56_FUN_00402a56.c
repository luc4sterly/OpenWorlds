// 00402a56 FUN_00402a56 [Global]
// programa: gdkup.exe

void __fastcall FUN_00402a56(undefined4 param_1,char param_2)

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


