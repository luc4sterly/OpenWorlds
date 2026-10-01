// 00433453 FUN_00433453 [Global]
// program: sfmain.exe

undefined8 __fastcall
FUN_00433453(undefined4 param_1,undefined4 param_2,double param_3,int param_4,undefined4 *param_5,
            undefined4 *param_6,int param_7,char *param_8)

{
  char cVar1;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  int extraout_EDX;
  char *pcVar5;
  char *pcVar6;
  float10 extraout_ST0;
  undefined8 uVar7;
  char local_44 [18];
  undefined2 uStack_32;
  undefined2 local_30;
  short sStack_2e;
  undefined2 local_2c;
  undefined2 uStack_2a;
  double local_28;
  int local_20;
  char local_1c;
  
  *param_6 = 0;
  *param_5 = 0;
  uVar7 = FUN_00433227(param_5,param_8,param_3._0_4_,param_3._4_4_,(undefined4 *)param_8);
  pcVar3 = (char *)((ulonglong)uVar7 >> 0x20);
  if ((int)uVar7 == 0) {
    local_30 = 0;
    sStack_2e = 0;
    local_2c = 0;
    uStack_2a = 0;
    if ((((ulonglong)param_3 & 0x7fffffff00000000) != 0) ||
       (piVar2 = extraout_ECX, param_3._0_4_ != 0)) {
      if (param_3 < 0.0) {
        param_3 = -param_3;
        *param_6 = 0xffffffff;
      }
      FUN_00433ba2(extraout_ECX,param_3._0_4_,param_3._0_4_,param_3._4_4_,extraout_ECX);
      iVar4 = *extraout_ECX_00;
      if (iVar4 < 0) {
        iVar4 = -iVar4;
      }
      iVar4 = (iVar4 * 3 + 5) / 10;
      if (*extraout_ECX_00 < 0) {
        iVar4 = -iVar4;
      }
      *extraout_ECX_00 = iVar4;
      if (param_7 == 0x46) {
        param_4 = param_4 + iVar4;
      }
      piVar2 = extraout_ECX_00;
      if (-1 < param_4) {
        if (0x10 < param_4) {
          param_4 = 0x10;
        }
        local_1c = '\0';
        FUN_004339c2(param_3._0_4_,param_3._4_4_,&local_28);
        if (((float10)0 == extraout_ST0) && (extraout_EDX < param_4)) {
          local_1c = '\x01';
          param_4 = extraout_EDX;
        }
        iVar4 = FUN_004332f5(param_3,param_4,(uint *)&local_30);
        piVar2 = extraout_ECX_01;
        if (iVar4 != 0) {
          *extraout_ECX_01 = *extraout_ECX_01 + iVar4;
          if ((param_7 == 0x46) || (local_1c != '\0')) {
            param_4 = param_4 + iVar4;
          }
          if (param_4 < 1) {
            param_4 = 1;
          }
          else if (0x10 < param_4) {
            param_4 = 0x10;
          }
          iVar4 = FUN_004332f5(param_3,param_4,(uint *)&local_30);
          piVar2 = extraout_ECX_02;
          if (0 < iVar4) {
            *extraout_ECX_02 = *extraout_ECX_02 + 1;
          }
        }
      }
      local_20 = (int)sStack_2e;
      if ((int)(CONCAT22(local_30,uStack_32) | CONCAT22(sStack_2e,local_30) |
                CONCAT22(local_2c,sStack_2e) | CONCAT22(uStack_2a,local_2c)) >> 0x10 == 0) {
        *param_6 = 0;
        *piVar2 = 0;
      }
    }
    pcVar5 = local_44;
    FUN_00433a81(piVar2,(int)local_44);
    pcVar6 = param_8;
    do {
      cVar1 = *pcVar5;
      *pcVar6 = cVar1;
      pcVar3 = param_8;
      if (cVar1 == '\0') break;
      cVar1 = pcVar5[1];
      pcVar5 = pcVar5 + 2;
      pcVar6[1] = cVar1;
      pcVar6 = pcVar6 + 2;
    } while (cVar1 != '\0');
  }
  return CONCAT44(param_2,pcVar3);
}


