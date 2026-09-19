// 10045570 __getenv_lk [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __getenv_lk
   
   Library: Visual Studio 1998 Release */

int __cdecl __getenv_lk(uchar *param_1)

{
  uchar uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  uchar *puVar7;
  char *pcVar8;
  
  if (DAT_1005beb8 == (int *)0x0) {
    if ((DAT_1005bec0 != 0) && (iVar3 = ___wtomb_environ(), iVar3 != 0)) {
      return 0;
    }
    if (DAT_1005beb8 == (int *)0x0) {
      return 0;
    }
  }
  if (param_1 != (uchar *)0x0) {
    uVar4 = 0xffffffff;
    puVar7 = param_1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      uVar1 = *puVar7;
      puVar7 = puVar7 + 1;
    } while (uVar1 != '\0');
    uVar4 = ~uVar4 - 1;
    iVar3 = *DAT_1005beb8;
    piVar6 = DAT_1005beb8;
    while (iVar3 != 0) {
      uVar5 = 0xffffffff;
      pcVar8 = (char *)*piVar6;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar2 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar2 != '\0');
      if (((uVar4 < ~uVar5 - 1) && (((uchar *)*piVar6)[uVar4] == '=')) &&
         (iVar3 = __mbsnbicoll((uchar *)*piVar6,param_1,uVar4), iVar3 == 0)) {
        return *piVar6 + 1 + uVar4;
      }
      piVar6 = piVar6 + 1;
      iVar3 = *piVar6;
    }
  }
  return 0;
}


