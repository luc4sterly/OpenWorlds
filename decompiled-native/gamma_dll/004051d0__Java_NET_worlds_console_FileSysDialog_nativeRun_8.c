// 004051d0 _Java_NET_worlds_console_FileSysDialog_nativeRun@8 [Global]
// program: gamma.dll

undefined4 _Java_NET_worlds_console_FileSysDialog_nativeRun_8(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  LPCSTR pCVar8;
  char *pcVar9;
  BOOL BVar10;
  int iVar11;
  int iVar12;
  tagOFNA *ptVar13;
  tagOFNA local_264 [3];
  char local_114 [260];
  
  ptVar13 = local_264;
                    /* 0x51d0  27  _Java_NET_worlds_console_FileSysDialog_nativeRun@8 */
  for (iVar11 = 0x13; iVar11 != 0; iVar11 = iVar11 + -1) {
    ptVar13->lStructSize = 0;
    ptVar13 = (tagOFNA *)&ptVar13->hwndOwner;
  }
  uVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_console_FileSysDialog_0046d738);
  uVar3 = (**(code **)(*param_1 + 0x178))
                    (param_1,uVar2,s_fileName_0046d770,s_Ljava_lang_String__0046d75c);
  uVar4 = (**(code **)(*param_1 + 0x178))
                    (param_1,uVar2,s_title_0046d77c,s_Ljava_lang_String__0046d75c);
  uVar5 = (**(code **)(*param_1 + 0x178))
                    (param_1,uVar2,s_typesAndExts_0046d784,s_Ljava_lang_String__0046d75c);
  uVar6 = (**(code **)(*param_1 + 0x178))(param_1,uVar2,&DAT_0046d798,&DAT_0046d794);
  uVar2 = (**(code **)(*param_1 + 0x178))(param_1,uVar2,&DAT_0046d7a0,&DAT_0046d794);
  local_264[0].pvReserved._0_1_ = '\0';
  local_114[0] = '\0';
  iVar11 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,uVar3);
  if (iVar11 != 0) {
    pcVar7 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,iVar11,0);
    FUN_0044d6b0((char *)&local_264[0].pvReserved,pcVar7);
    (**(code **)(*param_1 + 0x2a8))(param_1,iVar11,pcVar7);
  }
  pcVar7 = FUN_0044d7d0((char *)&local_264[0].pvReserved,'\\');
  if (pcVar7 == (char *)0x0) {
    FUN_0044d6b0(local_114,(char *)&local_264[0].pvReserved);
    local_264[0].pvReserved._0_1_ = '\0';
  }
  else {
    FUN_0044d6b0(local_114,pcVar7 + 1);
    if ((&local_264[0].pvReserved < pcVar7) && (pcVar7[-1] == ':')) {
      pcVar7[1] = '\0';
    }
    else {
      *pcVar7 = '\0';
    }
  }
  uVar3 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,uVar4);
  pCVar8 = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,uVar3,0);
  uVar4 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,uVar5);
  pcVar9 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,uVar4,0);
  iVar11 = -1;
  pcVar7 = pcVar9;
  do {
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  pcVar7 = (char *)FUN_00450b60(-iVar11);
  FUN_0044d6b0(pcVar7,pcVar9);
  (**(code **)(*param_1 + 0x2a8))(param_1,uVar4,pcVar9);
  iVar11 = 0;
  local_264[0].lpstrDefExt = (char *)0x0;
  for (iVar12 = 0; pcVar7[iVar12] != '\0'; iVar12 = iVar12 + 1) {
    if (pcVar7[iVar12] == '|') {
      iVar11 = iVar11 + 1;
      pcVar7[iVar12] = '\0';
      if (iVar11 == 1) {
        local_264[0].lpstrDefExt = pcVar7 + iVar12 + 1;
      }
    }
  }
  pcVar7[iVar12 + 1] = '\0';
  local_264[0].lStructSize = 0x4c;
  local_264[0].hwndOwner = (HWND)(**(code **)(*param_1 + 400))(param_1,param_2,uVar6);
  local_264[0].lpstrFile = local_114;
  local_264[0].nFilterIndex = 1;
  if ((char)local_264[0].pvReserved != '\0') {
    local_264[0].lpstrInitialDir = (LPCSTR)&local_264[0].pvReserved;
  }
  local_264[0].nMaxFile = 0x104;
  local_264[0].Flags = 0x180e;
  local_264[0].lpstrFilter = pcVar7;
  local_264[0].lpstrTitle = pCVar8;
  iVar11 = (**(code **)(*param_1 + 400))(param_1,param_2,uVar2);
  uVar2 = 0;
  if (iVar11 == 0) {
    BVar10 = GetOpenFileNameA(local_264);
    if (BVar10 == 0) goto LAB_004054c5;
  }
  else {
LAB_004054c5:
    if (iVar11 != 1) goto LAB_004054f1;
    BVar10 = GetSaveFileNameA(local_264);
    if (BVar10 == 0) goto LAB_004054f1;
  }
  uVar2 = (**(code **)(*param_1 + 0x29c))(param_1,local_114);
LAB_004054f1:
  (**(code **)(*param_1 + 0x2a8))(param_1,uVar3,pCVar8);
  return uVar2;
}


