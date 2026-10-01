// 00452510 FUN_00452510 [Global]
// program: gamma.dll

int * __thiscall FUN_00452510(void *this,int *param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char cVar9;
  int *this_00;
  bool bVar10;
  uint uVar11;
  uint uVar12;
  undefined1 uVar13;
  
  if (*(int *)*param_1 == 0) {
    return this;
  }
  if (**(int **)this != 0) {
    sVar1 = (short)param_1[1];
    sVar2 = *(short *)((int)this + 4);
    if (sVar1 < sVar2) {
      iVar3 = FUN_004088e0(param_1);
      uVar13 = 0;
      iVar4 = (int)sVar2 - (int)sVar1;
      uVar11 = 0;
      iVar5 = FUN_004088e0(param_1);
      FUN_00408f50(param_1,iVar3 - iVar5,uVar11,iVar4,uVar13);
      *(undefined2 *)(param_1 + 1) = *(undefined2 *)((int)this + 4);
    }
    else if (sVar2 < sVar1) {
      iVar3 = FUN_004088e0(this);
      uVar13 = 0;
      iVar4 = (int)sVar1 - (int)sVar2;
      uVar11 = 0;
      iVar5 = FUN_004088e0(this);
      FUN_00408f50(this,iVar3 - iVar5,uVar11,iVar4,uVar13);
      *(short *)((int)this + 4) = (short)param_1[1];
    }
    uVar11 = **(uint **)this;
    uVar12 = *(uint *)*param_1;
    this_00 = this;
    if ((uVar11 < uVar12) || (bVar10 = uVar12 < uVar11, this_00 = param_1, uVar12 = uVar11, bVar10))
    {
      FUN_004537e0(this_00,uVar12,0);
    }
    pcVar6 = (char *)FUN_004089f0(this);
    pcVar7 = (char *)FUN_004088e0(this);
    pcVar8 = (char *)FUN_004089f0(param_1);
    iVar3 = 0;
    cVar9 = '\0';
    while( true ) {
      pcVar6 = pcVar6 + -1;
      pcVar8 = pcVar8 + -1;
      if (pcVar6 <= pcVar7) break;
      *pcVar6 = *pcVar6 + (char)iVar3 + *pcVar8;
      if (*pcVar6 < '\n') {
        iVar3 = 0;
      }
      else {
        iVar3 = (int)*pcVar6 / 10;
        *pcVar6 = *pcVar6 % '\n';
      }
      cVar9 = (char)iVar3;
    }
    *pcVar6 = *pcVar6 + cVar9 + *pcVar8;
    cVar9 = *pcVar6;
    if ('\t' < cVar9) {
      *pcVar6 = *pcVar6 % '\n';
      iVar3 = FUN_004088e0(this);
      FUN_00408f50(this,(int)pcVar7 - iVar3,0,1,cVar9 / '\n');
      FUN_004088e0(this);
      *(short *)((int)this + 4) = *(short *)((int)this + 4) + 1;
    }
    if (**(int **)this != 0) {
      uVar11 = FUN_00453750(this,'\0',0xffffffff);
      if (uVar11 == 0xffffffff) {
        FUN_00408b80(this,0,'\0');
      }
      else if (uVar11 < **(int **)this - 1U) {
        FUN_004537e0(this,uVar11 + 1,0);
      }
    }
    return this;
  }
  FUN_004093a0(this,param_1,0,0xffffffff);
  *(short *)((int)this + 4) = (short)param_1[1];
  return this;
}


