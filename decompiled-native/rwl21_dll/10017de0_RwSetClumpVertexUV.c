// 10017de0 RwSetClumpVertexUV [Global]
// program: RWL21.DLL

int RwSetClumpVertexUV(int param_1,int param_2,float param_3,float param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  
                    /* 0x17de0  393  RwSetClumpVertexUV */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((uint)param_3 < 0x80000001) {
    if (((param_3 <= (float)*(uint *)(*(int *)(PTR_DAT_1005b69c + 0x2c4) + 0x74)) &&
        ((uint)param_4 < 0x80000001)) &&
       (param_4 <= (float)*(uint *)(*(int *)(PTR_DAT_1005b69c + 0x2c4) + 0x74))) {
      if ((0 < param_2) && (iVar2 = *(int *)(param_1 + 0x88), param_2 < *(int *)(iVar2 + 8) + -7)) {
        uVar4 = __ftol();
        if ((uVar4 & 0xffff0000) == 0) {
          iVar1 = (int)uVar4 + 0x100;
        }
        else {
          iVar1 = (int)uVar4 + -0x100;
        }
        iVar3 = (param_2 + 7) * 0x74;
        *(int *)(iVar3 + 0x70 + iVar2) = iVar1;
        uVar4 = __ftol();
        if ((uVar4 & 0xffff0000) == 0) {
          iVar2 = (int)uVar4 + 0x100;
        }
        else {
          iVar2 = (int)uVar4 + -0x100;
        }
        *(int *)(*(int *)(param_1 + 0x88) + 0x74 + iVar3) = iVar2;
        *(byte *)(*(int *)(param_1 + 0x88) + 0x54 + iVar3) =
             *(byte *)(*(int *)(param_1 + 0x88) + 0x54 + iVar3) | 0x80;
        return param_1;
      }
      FUN_1000cba0(0x19);
      return 0;
    }
  }
  FUN_1000cba0(0xb);
  return 0;
}


