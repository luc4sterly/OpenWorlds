// 004426b0 FUN_004426b0 [Global]
// program: gamma.dll

int __cdecl FUN_004426b0(byte *param_1,int param_2,char *param_3)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  char *pcVar5;
  byte local_24;
  byte local_20;
  byte local_1c;
  int local_14;
  
  iVar2 = 0;
  bVar3 = 0;
  local_14 = 0;
  if (0 < param_2) {
    do {
      iVar4 = 0;
      do {
        pcVar5 = param_3;
        local_24 = 0x20;
        local_20 = 0;
        do {
          bVar1 = bVar3 >> 1;
          bVar3 = bVar3 >> 1;
          if (bVar1 == 0) {
            local_1c = *param_1;
            param_1 = param_1 + 1;
            iVar2 = iVar2 + 1;
            bVar3 = 0x80;
          }
          if ((bVar3 & local_1c) != 0) {
            local_20 = local_20 | local_24;
          }
          local_24 = local_24 >> 1;
        } while (local_24 != 0);
        iVar4 = iVar4 + 1;
        *pcVar5 = local_20 << 2;
        param_3 = pcVar5 + 1;
      } while (iVar4 < 3);
      pcVar5[1] = '\0';
      local_14 = local_14 + 1;
      param_3 = pcVar5 + 2;
    } while (local_14 < param_2);
  }
  return iVar2;
}


