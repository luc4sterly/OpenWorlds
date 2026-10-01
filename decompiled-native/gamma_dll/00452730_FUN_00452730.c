// 00452730 FUN_00452730 [Global]
// program: gamma.dll

int * __thiscall FUN_00452730(void *this,int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  uint local_38;
  int *local_18;
  undefined4 local_14;
  
  if (**(int **)this == 0) {
    return this;
  }
  if (*(int *)*param_1 != 0) {
    FUN_00406490(&local_18,this);
    local_14 = CONCAT22(local_14._2_2_,*(undefined2 *)((int)this + 4));
    local_38 = 0;
    iVar5 = *local_18;
    iVar6 = *(int *)*param_1;
    iVar2 = FUN_004088e0((int *)&local_18);
    iVar3 = FUN_004088e0(param_1);
    FUN_00408b80(this,0,'\0');
    FUN_004537e0(this,(iVar5 + iVar6) - 1,0);
    pcVar4 = (char *)FUN_004089f0(this);
    iVar1 = **(int **)this;
    while (iVar1 = iVar1 + -1, -1 < iVar1) {
      iVar8 = iVar6 + -1;
      iVar9 = iVar1 - iVar8;
      if (iVar9 < 0) {
        iVar9 = 0;
        iVar8 = iVar1;
      }
      pcVar10 = (char *)(iVar2 + iVar9);
      pcVar11 = (char *)(iVar3 + iVar8 + 1);
      for (; (iVar9 < iVar5 && (-1 < iVar8)); iVar8 = iVar8 + -1) {
        pcVar11 = pcVar11 + -1;
        local_38 = local_38 + (int)*pcVar11 * (int)*pcVar10;
        iVar9 = iVar9 + 1;
        pcVar10 = pcVar10 + 1;
      }
      pcVar4 = pcVar4 + -1;
      *pcVar4 = (char)local_38 + (char)(local_38 / 10) * -10;
      local_38 = local_38 / 10;
    }
    *(short *)((int)this + 4) = (short)local_14 + (short)param_1[1];
    for (; local_38 != 0; local_38 = local_38 / 10) {
      iVar5 = FUN_004088e0(this);
      iVar6 = FUN_004088e0(this);
      FUN_00408f50(this,iVar5 - iVar6,0,1,(char)(local_38 % 10));
      FUN_004088e0(this);
      *(short *)((int)this + 4) = *(short *)((int)this + 4) + 1;
    }
    if (**(int **)this != 0) {
      uVar7 = FUN_00453750(this,'\0',0xffffffff);
      if (uVar7 == 0xffffffff) {
        FUN_00408b80(this,0,'\0');
      }
      else if (uVar7 < **(int **)this - 1U) {
        FUN_004537e0(this,uVar7 + 1,0);
      }
    }
    FUN_00404ed0((int *)&local_18);
    return this;
  }
  FUN_004093a0(this,param_1,0,0xffffffff);
  *(short *)((int)this + 4) = (short)param_1[1];
  return this;
}


