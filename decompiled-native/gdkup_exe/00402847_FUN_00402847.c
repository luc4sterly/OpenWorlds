// 00402847 FUN_00402847 [Global]
// programa: gdkup.exe

int FUN_00402847(void)

{
  char cVar1;
  char *in_EAX;
  uint uVar2;
  
  uVar2 = 0xffffffff;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *in_EAX;
    in_EAX = in_EAX + 1;
  } while (cVar1 != '\0');
  return ~uVar2 - 1;
}


