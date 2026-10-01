// 004328b3 FUN_004328b3 [Global]
// program: sfmain.exe

void __fastcall
FUN_004328b3(undefined4 param_1,undefined4 *param_2,int param_3,int param_4,undefined4 param_5,
            char param_6,char param_7)

{
  double dVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *in_EAX;
  int iVar4;
  undefined2 extraout_CX;
  char *extraout_ECX;
  undefined4 extraout_ECX_00;
  char *extraout_ECX_01;
  char *extraout_ECX_02;
  char *pcVar5;
  char *extraout_ECX_03;
  char *extraout_ECX_04;
  double *pdVar6;
  double *extraout_EDX;
  int unaff_EBX;
  int iVar7;
  float10 extraout_ST0;
  float10 fVar8;
  float10 extraout_ST0_00;
  undefined8 uVar9;
  char local_44 [20];
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  int local_1c;
  int local_18;
  char *local_14;
  char *local_10;
  
  local_10 = in_EAX;
  uVar9 = FUN_00433227(CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11((char)param_1,(char)param_1)
                               ),param_2,*param_2,param_2[1],(undefined4 *)local_44);
  pdVar6 = (double *)((ulonglong)uVar9 >> 0x20);
  if ((int)uVar9 == 0) {
    pcVar5 = (char *)CONCAT31((int3)((uint)extraout_ECX >> 8),param_7);
    if (CONCAT31((int3)((ulonglong)uVar9 >> 8),param_7) == 0x47) {
      local_30 = ABS(*pdVar6);
      if ((((ulonglong)local_30 & 0x7fffffff00000000) != 0) || ((int)local_30 != 0)) {
        uVar9 = thunk_FUN_0042bd10(pcVar5,pdVar6);
        dVar1 = (double)extraout_ST0;
        local_30._4_4_ = (undefined4)((ulonglong)dVar1 >> 0x20);
        uVar2 = local_30._4_4_;
        local_30._0_4_ = SUB84(dVar1,0);
        uVar3 = (int)local_30;
        local_30 = dVar1;
        FUN_004332b9(extraout_ECX_00,(int)((ulonglong)uVar9 >> 0x20),uVar3,uVar2);
        fVar8 = FUN_0042b8ce();
        local_18 = (int)ROUND(fVar8);
        pdVar6 = extraout_EDX;
        if ((local_18 < -4) || (unaff_EBX <= local_18)) {
          pcVar5 = (char *)CONCAT31((int3)((uint)extraout_ECX_01 >> 8),0x45);
          goto LAB_00432968;
        }
        if (0.0 <= local_30) {
          local_18 = local_18 + 1;
        }
        unaff_EBX = unaff_EBX - local_18;
        pcVar5 = extraout_ECX_01;
        if (local_18 < 0) {
          unaff_EBX = unaff_EBX + -1;
        }
      }
      pcVar5 = (char *)CONCAT31((int3)((uint)pcVar5 >> 8),0x46);
      param_4 = 0;
    }
LAB_00432968:
    if ((((uint)pcVar5 & 0xff) == 0x45) && ((param_4 <= -unaff_EBX || (unaff_EBX + 2 <= param_4))))
    goto LAB_00432983;
    if (param_7 == 'E') {
      if (param_4 < 1) {
        if (param_4 < 0) {
          unaff_EBX = param_4 + unaff_EBX;
        }
      }
      else {
        unaff_EBX = unaff_EBX + 1;
      }
    }
    local_28 = *pdVar6;
    if (((((*(uint *)((int)pdVar6 + 4) & 0x7fffffff) != 0) || (*(int *)pdVar6 != 0)) &&
        (((uint)pcVar5 & 0xff) != 0x45)) && (param_4 != 0)) {
      FUN_00433336(pcVar5,pdVar6,*(int *)pdVar6,*(uint *)((int)pdVar6 + 4),param_4);
      local_28 = (double)extraout_ST0_00;
      pcVar5 = extraout_ECX_02;
    }
    FUN_00433453(pcVar5,local_28._4_4_,local_28,unaff_EBX,&local_20,&local_1c,(uint)pcVar5 & 0xff,
                 local_44);
    local_14 = local_10;
    if (local_1c == 0) {
      if ((char)((ushort)extraout_CX >> 8) != '\0') {
        *local_10 = '+';
        local_14 = local_10 + 1;
      }
    }
    else {
      *local_10 = '-';
      local_14 = local_10 + 1;
    }
    iVar7 = param_3 + 1;
    if ((char)extraout_CX == 'E') {
      pcVar5 = (char *)(unaff_EBX - param_4);
      if ((int)pcVar5 <= param_3) {
        local_14 = FUN_004327df((int)pcVar5,local_44);
        iVar7 = (int)local_14 - (int)local_10;
        if ((param_6 != '\0') && (iVar7 < param_3)) {
          *local_14 = param_6;
          local_14 = local_14 + 1;
          iVar7 = iVar7 + 1;
        }
        if ((((ulonglong)local_28 & 0x7fffffff00000000) != 0) || ((int)local_28 != 0)) {
          local_20 = local_20 - param_4;
        }
        iVar4 = FUN_0043273c(param_3 - iVar7,local_20);
        iVar7 = iVar7 + iVar4;
        pcVar5 = extraout_ECX_03;
      }
    }
    else {
      pcVar5 = local_10;
      if ((int)(local_14 + ((local_20 + 1 + unaff_EBX) - (int)local_10)) <= param_3) {
        pcVar5 = FUN_004327df(unaff_EBX,local_44);
        iVar7 = (int)pcVar5 - (int)local_10;
        pcVar5 = extraout_ECX_04;
      }
    }
  }
  else {
    for (iVar7 = 0; pcVar5 = extraout_ECX, local_44[iVar7] != '\0'; iVar7 = iVar7 + 1) {
      if (iVar7 < param_3) {
        *local_10 = local_44[iVar7];
      }
      local_10 = local_10 + 1;
    }
  }
  if (iVar7 <= param_3) {
    FUN_00432842(pcVar5,iVar7);
    return;
  }
LAB_00432983:
  FUN_00408098(pcVar5,0x2a);
  return;
}


