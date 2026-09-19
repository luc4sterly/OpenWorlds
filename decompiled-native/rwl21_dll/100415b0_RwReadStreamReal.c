// 100415b0 RwReadStreamReal [Global]
// programa: RWL21.DLL

void RwReadStreamReal(int *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
                    /* 0x415b0  329  RwReadStreamReal */
  uVar2 = param_3 >> 2;
  RwReadStream(param_1,param_2,param_3);
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    uVar1 = *param_2;
    *param_2 = (uVar1 & 0xff00 | uVar1 << 0x10) << 8 | (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8;
    param_2 = param_2 + 1;
  }
  return;
}


