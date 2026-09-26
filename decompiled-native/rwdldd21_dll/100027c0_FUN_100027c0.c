// 100027c0 FUN_100027c0 [Global]
// programa: RWDLDD21.DLL

uint FUN_100027c0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = DAT_10038a90 & param_1;
  uVar2 = DAT_10038a88 & param_1;
  uVar4 = DAT_10038af8 & param_1;
  uVar3 = DAT_10038b58;
  if (DAT_10038b58 == 0) {
    uVar3 = DAT_10038af8 | DAT_10038a88 | DAT_10038a90;
  }
  uVar3 = ((param_1 & uVar3) == 0) - 1;
  if ((DAT_10038b04 == 0) && (uVar3 == 0)) {
    uVar4 = 0;
    uVar2 = 0;
    uVar1 = 0;
  }
  if (DAT_10038b6c == 0) {
    uVar1 = uVar1 >> (DAT_10038a58 & 0x1f);
  }
  else {
    uVar1 = uVar1 << (DAT_10038a58 & 0x1f);
  }
  if (DAT_10038b2c == 0) {
    uVar2 = uVar2 >> (DAT_10038b30 & 0x1f);
  }
  else {
    uVar2 = uVar2 << (DAT_10038b30 & 0x1f);
  }
  if (DAT_10038b28 == 0) {
    uVar4 = uVar4 >> (DAT_10038afc & 0x1f);
  }
  else {
    uVar4 = uVar4 << (DAT_10038afc & 0x1f);
  }
  return uVar1 & DAT_10038ad0 | uVar4 & DAT_10038a54 | uVar3 & DAT_10038b04 | uVar2 & DAT_10038a18;
}


