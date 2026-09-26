// 00403162 FUN_00403162 [Global]
// programa: run.exe

int FUN_00403162(void)

{
  char cVar1;
  byte bVar2;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  byte *this;
  byte unaff_BL;
  char local_1230 [4240];
  char local_1a0 [260];
  DWORD local_9c;
  uint local_98;
  DWORD local_8c;
  CHAR aCStackY_18 [4];
  
  FUN_004062f0();
  local_9c = 0x94;
  BVar3 = GetVersionExA((LPOSVERSIONINFOA)&local_9c);
  if (((BVar3 == 0) || (local_8c != 2)) || (local_98 < 5)) {
    aCStackY_18[0] = -0x44;
    aCStackY_18[1] = '1';
    aCStackY_18[2] = '@';
    aCStackY_18[3] = '\0';
    DVar4 = GetEnvironmentVariableA("__MSVCRT_HEAP_SELECT",local_1230,0x1090);
    if (DVar4 != 0) {
      pcVar7 = local_1230;
      while (local_1230[0] != '\0') {
        cVar1 = *pcVar7;
        if (('`' < cVar1) && (cVar1 < '{')) {
          *pcVar7 = cVar1 + -0x20;
        }
        pcVar7 = pcVar7 + 1;
        local_1230[0] = *pcVar7;
      }
      aCStackY_18[0] = -6;
      aCStackY_18[1] = '1';
      aCStackY_18[2] = '@';
      aCStackY_18[3] = '\0';
      iVar5 = _strncmp("__GLOBAL_HEAP_SELECTED",local_1230,0x16);
      if (iVar5 == 0) {
        pcVar7 = local_1230;
      }
      else {
        builtin_memcpy(aCStackY_18,"\x1c2@",4);
        GetModuleFileNameA((HMODULE)0x0,local_1a0,0x104);
        pcVar7 = local_1a0;
        while (local_1a0[0] != '\0') {
          cVar1 = *pcVar7;
          if (('`' < cVar1) && (cVar1 < '{')) {
            *pcVar7 = cVar1 + -0x20;
          }
          pcVar7 = pcVar7 + 1;
          local_1a0[0] = *pcVar7;
        }
        pcVar7 = _strstr(local_1230,local_1a0);
      }
      if ((pcVar7 != (char *)0x0) && (pcVar7 = _strchr(pcVar7,0x2c), pcVar7 != (char *)0x0)) {
        pbVar6 = (byte *)(pcVar7 + 1);
        bVar2 = *pbVar6;
        this = pbVar6;
        while (bVar2 != 0) {
          if (*this == 0x3b) {
            *this = 0;
          }
          else {
            this = this + 1;
          }
          bVar2 = *this;
        }
        aCStackY_18[0] = -0x7e;
        aCStackY_18[1] = '2';
        aCStackY_18[2] = '@';
        aCStackY_18[3] = '\0';
        iVar5 = FUN_00405f35(this,pbVar6,(int *)0x0,(void *)0xa);
        if (iVar5 == 2) {
          return 2;
        }
        if (iVar5 == 3) {
          return 3;
        }
        if (iVar5 == 1) {
          return 1;
        }
      }
    }
    FUN_00403135((undefined4 *)&stack0xfffffff8);
    iVar5 = 3 - (uint)(unaff_BL < 6);
  }
  else {
    iVar5 = 1;
  }
  return iVar5;
}


