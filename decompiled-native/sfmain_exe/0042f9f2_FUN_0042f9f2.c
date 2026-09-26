// 0042f9f2 FUN_0042f9f2 [Global]
// programa: sfmain.exe

char * __fastcall FUN_0042f9f2(undefined4 param_1,int param_2)

{
  char *in_EAX;
  char *pcVar1;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar2;
  int iVar3;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  iVar3 = -1;
  if (*in_EAX == 'J') {
    iVar3 = 1;
    in_EAX = in_EAX + 1;
  }
  if (*in_EAX == 'M') {
    iVar3 = 0;
  }
  *(int *)(param_2 + 0x20) = iVar3;
  pcVar1 = (char *)FUN_0042f8a5(param_2,&local_10);
  piVar2 = extraout_ECX;
  if (iVar3 == 0) {
    extraout_ECX[4] = local_10 + -1;
    if (*pcVar1 == '.') {
      pcVar1 = (char *)FUN_0042f8a5(extraout_ECX,&local_10);
      extraout_ECX_00[3] = local_10;
      piVar2 = extraout_ECX_00;
      if (*pcVar1 == '.') {
        pcVar1 = (char *)FUN_0042f8a5(extraout_ECX_00,&local_10);
        extraout_ECX_01[6] = local_10;
        piVar2 = extraout_ECX_01;
      }
    }
    piVar2[7] = 0;
  }
  else {
    extraout_ECX[7] = local_10;
  }
  local_14 = 2;
  local_1c = 0;
  local_18 = 0;
  if (*pcVar1 == '/') {
    pcVar1 = (char *)FUN_0042f8a5(piVar2,&local_14);
    piVar2 = extraout_ECX_02;
    if (*pcVar1 == ':') {
      pcVar1 = (char *)FUN_0042f8a5(extraout_ECX_02,&local_18);
      piVar2 = extraout_ECX_03;
      if (*pcVar1 == ':') {
        pcVar1 = (char *)FUN_0042f8a5(extraout_ECX_03,&local_1c);
        piVar2 = extraout_ECX_04;
      }
    }
  }
  *piVar2 = local_1c;
  piVar2[1] = local_18;
  piVar2[2] = local_14;
  return pcVar1;
}


