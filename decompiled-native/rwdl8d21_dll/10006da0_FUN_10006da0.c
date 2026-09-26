// 10006da0 FUN_10006da0 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_10006da0(undefined4 param_1)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  byte local_10c;
  double local_100 [32];
  
  DAT_100781d0 = 0;
  DAT_100780d0 = 0;
  local_100[0] = (double)_DAT_1007523c;
  iVar1 = 1;
  do {
    iVar3 = iVar1 + 1;
    FUN_10059662(param_1);
    lVar5 = __ftol();
    (&DAT_100781d0)[iVar1] = (char)lVar5;
    FUN_10059662(extraout_ECX);
    lVar5 = __ftol();
    (&DAT_100780d0)[iVar1] = (char)lVar5;
    param_1 = extraout_ECX_00;
    iVar1 = iVar3;
  } while (iVar3 < 0x100);
  iVar3 = 0;
  iVar1 = 0;
  do {
    local_10c = (byte)iVar1;
    if ((*(uint *)(&DAT_100751e8 + (local_10c >> 3 & 0xfffffffc)) & 1 << (local_10c & 0x1f)) != 0) {
      iVar4 = 0;
      if (0 < iVar3) {
        do {
          uVar2 = (uint)*(byte *)((int)local_100 + iVar4);
          if ((&DAT_100781d0)[*(byte *)((int)&DAT_10077ec0 + uVar2)] ==
              (&DAT_100781d0)[*(byte *)((int)&DAT_10077ec0 + iVar1)]) {
            if (((&DAT_100781d0)[*(byte *)((int)&DAT_10077fc0 + uVar2)] ==
                 (&DAT_100781d0)[*(byte *)((int)&DAT_10077fc0 + iVar1)]) &&
               ((&DAT_100781d0)[*(byte *)((int)&DAT_10077db0 + uVar2)] ==
                (&DAT_100781d0)[*(byte *)((int)&DAT_10077db0 + iVar1)])) break;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar3);
      }
      if (iVar4 == iVar3) {
        *(byte *)((int)local_100 + iVar3) = local_10c;
        iVar3 = iVar3 + 1;
      }
    }
    iVar1 = iVar1 + 1;
    if (0xff < iVar1) {
      FUN_1000b520(iVar3,(int)local_100);
      return;
    }
  } while( true );
}


