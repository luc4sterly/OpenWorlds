// 100322b0 rwSetClumpVertices [Global]
// programa: RWL21.DLL

/* rwSetClumpVertices */

int __cdecl rwSetClumpVertices(int param_1,int *param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x322b0  535  _rwSetClumpVertices */
  iVar3 = FUN_10041c90(*(int *)(param_1 + 0x88),0);
  if (0 < param_4) {
    do {
      iVar2 = *param_2;
      param_2 = param_2 + 1;
      param_4 = param_4 + -1;
      puVar1 = (undefined4 *)(iVar3 + iVar2 * 0x74);
      *puVar1 = *param_3;
      puVar1[1] = param_3[1];
      puVar1[2] = param_3[2];
      param_3 = param_3 + 3;
    } while (param_4 != 0);
  }
  return param_1;
}


