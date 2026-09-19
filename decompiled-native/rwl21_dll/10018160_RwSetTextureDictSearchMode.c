// 10018160 RwSetTextureDictSearchMode [Global]
// programa: RWL21.DLL

undefined4 RwSetTextureDictSearchMode(int param_1)

{
                    /* 0x18160  471  RwSetTextureDictSearchMode */
  if ((param_1 != 1) && (param_1 != 2)) {
    FUN_1000cba0(0x2f);
    return 0;
  }
  DAT_1005ac00 = param_1;
  return 1;
}


