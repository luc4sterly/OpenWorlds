// 1001ec70 RwGetSplineNumPoints [Global]
// programa: RWL21.DLL

int RwGetSplineNumPoints(int *param_1)

{
                    /* 0x1ec70  246  RwGetSplineNumPoints */
  if (param_1 == (int *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  if (param_1[1] != 1) {
    if (param_1[1] != 2) {
      FUN_1000cba0(0x11);
      return 0;
    }
    return *param_1 + -3;
  }
  return *param_1 + -2;
}


