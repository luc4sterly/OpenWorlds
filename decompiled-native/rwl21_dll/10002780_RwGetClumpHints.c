// 10002780 RwGetClumpHints [Global]
// program: RWL21.DLL

undefined4 RwGetClumpHints(int param_1)

{
                    /* 0x2780  149  RwGetClumpHints */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x188);
  }
  FUN_1000cba0(1);
  return 0;
}


