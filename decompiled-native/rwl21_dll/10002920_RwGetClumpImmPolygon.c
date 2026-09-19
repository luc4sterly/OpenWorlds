// 10002920 RwGetClumpImmPolygon [Global]
// programa: RWL21.DLL

int RwGetClumpImmPolygon(int param_1,int param_2)

{
                    /* 0x2920  150  RwGetClumpImmPolygon */
  if (**(int **)(param_1 + 0x9c) != 0) {
    FUN_1000cba0(0x4c);
    return 0;
  }
  if ((0 < param_2) && (param_2 <= **(int **)(param_1 + 0x98))) {
    return (*(int **)(param_1 + 0x98))[param_2 + 1];
  }
  FUN_1000cba0(0x4b);
  return 0;
}


