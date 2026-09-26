// 0042c5ad FUN_0042c5ad [Global]
// programa: sfmain.exe

int FUN_0042c5ad(void)

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


