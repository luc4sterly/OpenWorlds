// 100028d0 RwGetClumpImmVertex [Global]
// program: RWL21.DLL

int RwGetClumpImmVertex(int param_1,int param_2)

{
                    /* 0x28d0  151  RwGetClumpImmVertex */
  if ((0 < param_2) && (param_2 < *(int *)(*(int *)(param_1 + 0x88) + 8) + -7)) {
    return *(int *)(param_1 + 0x88) + 0xc + (param_2 + 7) * 0x74;
  }
  FUN_1000cba0(0x19);
  return 0;
}


