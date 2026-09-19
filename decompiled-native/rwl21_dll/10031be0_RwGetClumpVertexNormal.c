// 10031be0 RwGetClumpVertexNormal [Global]
// programa: RWL21.DLL

undefined4 * RwGetClumpVertexNormal(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
                    /* 0x31be0  169  RwGetClumpVertexNormal */
  if ((param_1 == 0) || (param_3 == (undefined4 *)0x0)) {
    FUN_1000cba0(1);
    return (undefined4 *)0x0;
  }
  if ((0 < param_2) && (param_2 < *(int *)(*(int *)(param_1 + 0x88) + 8) + -7)) {
    iVar1 = FUN_10041c90(*(int *)(param_1 + 0x88),param_2);
    *param_3 = *(undefined4 *)(iVar1 + 0x4c);
    param_3[1] = *(undefined4 *)(iVar1 + 0x50);
    param_3[2] = *(undefined4 *)(iVar1 + 0x54);
    return param_3;
  }
  FUN_1000cba0(0x19);
  return (undefined4 *)0x0;
}


