// 10020800 FUN_10020800 [Global]
// programa: RWL21.DLL

int __cdecl FUN_10020800(FILE *param_1,char *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  char local_200 [256];
  char local_100 [256];
  
  puVar4 = (undefined4 *)&stack0x0000000c;
  iVar5 = 0;
  cVar1 = *param_2;
  while( true ) {
    if (cVar1 == '\0') {
      return iVar5;
    }
    pcVar6 = param_2 + 1;
    if (*param_2 != '%') break;
    param_2 = param_2 + 2;
    switch(*pcVar6) {
    case 'D':
    case 'd':
      uVar2 = *puVar4;
      iVar3 = FUN_100206d0(param_1,local_200,0x100);
      if (((iVar3 != 1) || (local_200[0] == '#')) ||
         (iVar3 = _sscanf(local_200,&DAT_1005acc8,uVar2), iVar3 == 0)) {
        return iVar5;
      }
      break;
    default:
      FUN_1000cba0(0x6b);
      return iVar5;
    case 'F':
    case 'f':
      uVar2 = *puVar4;
      iVar3 = FUN_100206d0(param_1,local_100,0x100);
      if (((iVar3 != 1) || (local_100[0] == '#')) ||
         (iVar3 = _sscanf(local_100,&DAT_1005ab48,uVar2), iVar3 == 0)) {
        return iVar5;
      }
      break;
    case 'S':
    case 's':
      iVar3 = FUN_100206d0(param_1,(char *)*puVar4,100);
      if (iVar3 == 0) {
        return iVar5;
      }
    }
    puVar4 = puVar4 + 1;
    iVar5 = iVar5 + 1;
    cVar1 = *param_2;
  }
  FUN_1000cba0(0x6b);
  return iVar5;
}


