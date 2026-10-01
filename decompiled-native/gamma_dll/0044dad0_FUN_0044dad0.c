// 0044dad0 FUN_0044dad0 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_0044dad0(int param_1,char *param_2,DWORD param_3)

{
  char cVar1;
  undefined4 *puVar2;
  LPVOID pvVar3;
  BOOL BVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  uint local_14;
  
  if ((param_1 < 0x100) &&
     (puVar2 = (undefined4 *)(&DAT_0049f448)[param_1], puVar2 != (undefined4 *)0x0)) {
    cVar1 = *(char *)(puVar2 + 1);
    BVar4 = ReadFile((HANDLE)*puVar2,param_2,param_3,&local_14,(LPOVERLAPPED)0x0);
    if (BVar4 != 0) {
      if ((local_14 != 0) && (cVar1 != '\0')) {
        iVar6 = 0;
        pcVar5 = param_2;
        pcVar8 = param_2;
        for (uVar7 = 0; uVar7 < local_14; uVar7 = uVar7 + 1) {
          if (((*pcVar5 == '\r') && (uVar7 < local_14 - 1)) && (pcVar5[1] == '\n')) {
            iVar6 = iVar6 + 1;
          }
          else {
            *pcVar8 = *pcVar5;
            pcVar8 = pcVar8 + 1;
          }
          pcVar5 = pcVar5 + 1;
        }
        if (((local_14 == param_3) && (1 < local_14)) && (param_2[local_14 - 1] == '\r')) {
          FUN_0044da60(param_1,-1,1);
          iVar6 = iVar6 + 1;
        }
        local_14 = local_14 - iVar6;
      }
      return local_14;
    }
    _DAT_0049ff4c = GetLastError();
    return 0;
  }
  pvVar3 = FUN_00453ed0();
  *(undefined4 *)((int)pvVar3 + 4) = 3;
  return 0xffffffff;
}


