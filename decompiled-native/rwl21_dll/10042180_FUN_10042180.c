// 10042180 FUN_10042180 [Global]
// programa: RWL21.DLL

void FUN_10042180(int param_1,int param_2)

{
  ushort uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 0x6c);
  iVar4 = 0;
  if (uVar1 != 0) {
    piVar2 = *(int **)(param_1 + 0x70);
    piVar3 = piVar2;
    while (*piVar3 != param_2) {
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + 1;
      if ((int)(uint)uVar1 <= iVar4) {
        return;
      }
    }
    piVar2[iVar4] = piVar2[uVar1 - 1];
    *(short *)(param_1 + 0x6c) = *(short *)(param_1 + 0x6c) + -1;
    FUN_10041df0(param_1);
    FUN_10041ec0(param_1);
  }
  return;
}


