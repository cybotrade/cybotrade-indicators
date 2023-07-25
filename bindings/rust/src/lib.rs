#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

use thiserror::Error;
use validator::{Validate, ValidationError, ValidationErrors};

#[link(name = "indicators")]
extern "C" {}

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct BuySellSignal;
impl BuySellSignal {
    pub const Nothing: f64 = 0.0;
    pub const Buy: f64 = 1.0;
    pub const Sell: f64 = -1.0;
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct DirectionSignal;
impl DirectionSignal {
    pub const Nothing: f64 = 0.0;
    pub const Up: f64 = 1.0;
    pub const Down: f64 = -1.0;
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct BarColor;
impl BarColor {
    pub const Nothing: f64 = 0.0;
    pub const Green: f64 = 1.0;
    pub const Red: f64 = -1.0;
}

#[derive(Debug, Error)]
pub enum IndicatorError {
    #[error("Failed to validate: {0}")]
    Validation(#[from] ValidationErrors),

    #[error("Invalid indicator index: {0}")]
    InvalidIndicatorIndex(u32),

    #[error("Invalid options: {0}")]
    InvalidOption(String),

    #[error("Out of memory")]
    OutOfMemory,

    #[error("Unknown")]
    Unknown,
}

type IndicatorFn = unsafe extern "C" fn(i32, *const *const f64, *const f64, *const *mut f64) -> i32;
type StartFn = unsafe extern "C" fn(*const f64) -> i32;

fn get_indicator(index: u32) -> Result<(IndicatorFn, StartFn), IndicatorError> {
    let indicator = match index {
        TI_INDICATOR_ABS_INDEX => ti_abs,
        TI_INDICATOR_ACOS_INDEX => ti_acos,
        TI_INDICATOR_AD_INDEX => ti_ad,
        TI_INDICATOR_ADD_INDEX => ti_add,
        TI_INDICATOR_ADOSC_INDEX => ti_adosc,
        TI_INDICATOR_ADX_INDEX => ti_adx,
        TI_INDICATOR_ADXR_INDEX => ti_adxr,
        TI_INDICATOR_ANDEAN_OSC_INDEX => ti_andean_osc,
        TI_INDICATOR_AO_INDEX => ti_ao,
        TI_INDICATOR_APO_INDEX => ti_apo,
        TI_INDICATOR_AROON_INDEX => ti_aroon,
        TI_INDICATOR_AROONOSC_INDEX => ti_aroonosc,
        TI_INDICATOR_ASIN_INDEX => ti_asin,
        TI_INDICATOR_ATAN_INDEX => ti_atan,
        TI_INDICATOR_ATR_INDEX => ti_atr,
        TI_INDICATOR_AVGPRICE_INDEX => ti_avgprice,
        TI_INDICATOR_BBANDS_INDEX => ti_bbands,
        TI_INDICATOR_BOOM_PRO_INDEX => ti_boom_pro,
        TI_INDICATOR_BOP_INDEX => ti_bop,
        TI_INDICATOR_BRAID_FILTER_INDEX => ti_braid_filter,
        TI_INDICATOR_CCI_INDEX => ti_cci,
        TI_INDICATOR_CEIL_INDEX => ti_ceil,
        TI_INDICATOR_CHANDELIER_EXIT_INDEX => ti_chandelier_exit,
        TI_INDICATOR_CM_EMA_TRENDBARS_INDEX => ti_cm_ema_trendbars,
        TI_INDICATOR_CMO_INDEX => ti_cmo,
        TI_INDICATOR_COS_INDEX => ti_cos,
        TI_INDICATOR_COSH_INDEX => ti_cosh,
        TI_INDICATOR_CROSSANY_INDEX => ti_crossany,
        TI_INDICATOR_CROSSOVER_INDEX => ti_crossover,
        TI_INDICATOR_CVI_INDEX => ti_cvi,
        TI_INDICATOR_DECAY_INDEX => ti_decay,
        TI_INDICATOR_DEMA_INDEX => ti_dema,
        TI_INDICATOR_DI_INDEX => ti_di,
        TI_INDICATOR_DI_DX_INDEX => ti_di_dx,
        TI_INDICATOR_DIV_INDEX => ti_div,
        TI_INDICATOR_DM_INDEX => ti_dm,
        TI_INDICATOR_DPO_INDEX => ti_dpo,
        TI_INDICATOR_DX_INDEX => ti_dx,
        TI_INDICATOR_EDECAY_INDEX => ti_edecay,
        TI_INDICATOR_EMA_INDEX => ti_ema,
        TI_INDICATOR_EMV_INDEX => ti_emv,
        TI_INDICATOR_EXP_INDEX => ti_exp,
        TI_INDICATOR_FLOOR_INDEX => ti_floor,
        TI_INDICATOR_FOSC_INDEX => ti_fosc,
        TI_INDICATOR_HA_INDEX => ti_ha,
        TI_INDICATOR_HALF_TREND_INDEX => ti_half_trend,
        TI_INDICATOR_HEATMAP_VOL_INDEX => ti_heatmap_vol,
        TI_INDICATOR_HLC3_INDEX => ti_hlc3,
        TI_INDICATOR_HMA_INDEX => ti_hma,
        TI_INDICATOR_HULL_SUITE_INDEX => ti_hull_suite,
        TI_INDICATOR_INSIDEBAR_INDEX => ti_insidebar,
        TI_INDICATOR_KAMA_INDEX => ti_kama,
        TI_INDICATOR_KVO_INDEX => ti_kvo,
        TI_INDICATOR_LAG_INDEX => ti_lag,
        TI_INDICATOR_LINREG_INDEX => ti_linreg,
        TI_INDICATOR_LINREGINTERCEPT_INDEX => ti_linregintercept,
        TI_INDICATOR_LINREGSLOPE_INDEX => ti_linregslope,
        TI_INDICATOR_LN_INDEX => ti_ln,
        TI_INDICATOR_LOG10_INDEX => ti_log10,
        TI_INDICATOR_MACD_INDEX => ti_macd,
        TI_INDICATOR_MACD_FASTLINE_DIVERGENCE_INDEX => ti_macd_fastline_divergence,
        TI_INDICATOR_MACD_HIST_DIVERGENCE_INDEX => ti_macd_hist_divergence,
        TI_INDICATOR_MARKETFI_INDEX => ti_marketfi,
        TI_INDICATOR_MASS_INDEX => ti_mass,
        TI_INDICATOR_MAX_INDEX => ti_max,
        TI_INDICATOR_MD_INDEX => ti_md,
        TI_INDICATOR_MEDPRICE_INDEX => ti_medprice,
        TI_INDICATOR_MFI_INDEX => ti_mfi,
        TI_INDICATOR_MIN_INDEX => ti_min,
        TI_INDICATOR_MOBO_BAND_INDEX => ti_mobo_band,
        TI_INDICATOR_MOM_INDEX => ti_mom,
        TI_INDICATOR_MUL_INDEX => ti_mul,
        TI_INDICATOR_NATR_INDEX => ti_natr,
        TI_INDICATOR_PRICE_INDEX => ti_price,
        TI_INDICATOR_PSAR_INDEX => ti_psar,
        TI_INDICATOR_QQE_MOD_INDEX => ti_qqe_mod,
        TI_INDICATOR_ROC_INDEX => ti_roc,
        TI_INDICATOR_ROCR_INDEX => ti_rocr,
        TI_INDICATOR_ROUND_INDEX => ti_round,
        TI_INDICATOR_RSI_INDEX => ti_rsi,
        TI_INDICATOR_RSI_DIVERGENCE_INDEX => ti_rsi_divergence,
        TI_INDICATOR_RVI_INDEX => ti_rvi,
        TI_INDICATOR_RVI_DIVERGENCE_INDEX => ti_rvi_divergence,
        TI_INDICATOR_SIN_INDEX => ti_sin,
        TI_INDICATOR_SINH_INDEX => ti_sinh,
        TI_INDICATOR_SMA_INDEX => ti_sma,
        TI_INDICATOR_SQRT_INDEX => ti_sqrt,
        TI_INDICATOR_SSL_INDEX => ti_ssl,
        TI_INDICATOR_STC_INDEX => ti_stc,
        TI_INDICATOR_STDDEV_INDEX => ti_stddev,
        TI_INDICATOR_STDERR_INDEX => ti_stderr,
        TI_INDICATOR_STOCH_INDEX => ti_stoch,
        TI_INDICATOR_STOCH_DIVERGENCE_INDEX => ti_stoch_divergence,
        TI_INDICATOR_STOCHRSI_INDEX => ti_stochrsi,
        TI_INDICATOR_SUB_INDEX => ti_sub,
        TI_INDICATOR_SUM_INDEX => ti_sum,
        TI_INDICATOR_SUP_AND_RES_INDEX => ti_sup_and_res,
        TI_INDICATOR_SUPERTREND_INDEX => ti_supertrend,
        TI_INDICATOR_TAN_INDEX => ti_tan,
        TI_INDICATOR_TANH_INDEX => ti_tanh,
        TI_INDICATOR_TEMA_INDEX => ti_tema,
        TI_INDICATOR_TODEG_INDEX => ti_todeg,
        TI_INDICATOR_TORAD_INDEX => ti_torad,
        TI_INDICATOR_TR_INDEX => ti_tr,
        TI_INDICATOR_TRIMA_INDEX => ti_trima,
        TI_INDICATOR_TRIX_INDEX => ti_trix,
        TI_INDICATOR_TRUNC_INDEX => ti_trunc,
        TI_INDICATOR_TSF_INDEX => ti_tsf,
        TI_INDICATOR_TYPPRICE_INDEX => ti_typprice,
        TI_INDICATOR_ULTOSC_INDEX => ti_ultosc,
        TI_INDICATOR_UNSHIFT_INDEX => ti_unshift,
        TI_INDICATOR_UT_BOT_INDEX => ti_ut_bot,
        TI_INDICATOR_VAR_INDEX => ti_var,
        TI_INDICATOR_VHF_INDEX => ti_vhf,
        TI_INDICATOR_VOLATILITY_INDEX => ti_volatility,
        TI_INDICATOR_VOLATILITY_OSCILLATOR_INDEX => ti_volatility_oscillator,
        TI_INDICATOR_VOSC_INDEX => ti_vosc,
        TI_INDICATOR_VU_MAN_CHU_SWING_INDEX => ti_vu_man_chu_swing,
        TI_INDICATOR_VWMA_INDEX => ti_vwma,
        TI_INDICATOR_WAD_INDEX => ti_wad,
        TI_INDICATOR_WADDAH_INDEX => ti_waddah,
        TI_INDICATOR_WAVETREND_INDEX => ti_wavetrend,
        TI_INDICATOR_WCPRICE_INDEX => ti_wcprice,
        TI_INDICATOR_WILDERS_INDEX => ti_wilders,
        TI_INDICATOR_WILLR_INDEX => ti_willr,
        TI_INDICATOR_WMA_INDEX => ti_wma,
        TI_INDICATOR_ZLEMA_INDEX => ti_zlema,
        _ => return Err(IndicatorError::InvalidIndicatorIndex(index)),
    };
    let start = match index {
        TI_INDICATOR_ABS_INDEX => ti_abs_start,
        TI_INDICATOR_ACOS_INDEX => ti_acos_start,
        TI_INDICATOR_AD_INDEX => ti_ad_start,
        TI_INDICATOR_ADD_INDEX => ti_add_start,
        TI_INDICATOR_ADOSC_INDEX => ti_adosc_start,
        TI_INDICATOR_ADX_INDEX => ti_adx_start,
        TI_INDICATOR_ADXR_INDEX => ti_adxr_start,
        TI_INDICATOR_ANDEAN_OSC_INDEX => ti_andean_osc_start,
        TI_INDICATOR_AO_INDEX => ti_ao_start,
        TI_INDICATOR_APO_INDEX => ti_apo_start,
        TI_INDICATOR_AROON_INDEX => ti_aroon_start,
        TI_INDICATOR_AROONOSC_INDEX => ti_aroonosc_start,
        TI_INDICATOR_ASIN_INDEX => ti_asin_start,
        TI_INDICATOR_ATAN_INDEX => ti_atan_start,
        TI_INDICATOR_ATR_INDEX => ti_atr_start,
        TI_INDICATOR_AVGPRICE_INDEX => ti_avgprice_start,
        TI_INDICATOR_BBANDS_INDEX => ti_bbands_start,
        TI_INDICATOR_BOOM_PRO_INDEX => ti_boom_pro_start,
        TI_INDICATOR_BOP_INDEX => ti_bop_start,
        TI_INDICATOR_BRAID_FILTER_INDEX => ti_braid_filter_start,
        TI_INDICATOR_CCI_INDEX => ti_cci_start,
        TI_INDICATOR_CEIL_INDEX => ti_ceil_start,
        TI_INDICATOR_CHANDELIER_EXIT_INDEX => ti_chandelier_exit_start,
        TI_INDICATOR_CM_EMA_TRENDBARS_INDEX => ti_cm_ema_trendbars_start,
        TI_INDICATOR_CMO_INDEX => ti_cmo_start,
        TI_INDICATOR_COS_INDEX => ti_cos_start,
        TI_INDICATOR_COSH_INDEX => ti_cosh_start,
        TI_INDICATOR_CROSSANY_INDEX => ti_crossany_start,
        TI_INDICATOR_CROSSOVER_INDEX => ti_crossover_start,
        TI_INDICATOR_CVI_INDEX => ti_cvi_start,
        TI_INDICATOR_DECAY_INDEX => ti_decay_start,
        TI_INDICATOR_DEMA_INDEX => ti_dema_start,
        TI_INDICATOR_DI_INDEX => ti_di_start,
        TI_INDICATOR_DI_DX_INDEX => ti_di_dx_start,
        TI_INDICATOR_DIV_INDEX => ti_div_start,
        TI_INDICATOR_DM_INDEX => ti_dm_start,
        TI_INDICATOR_DPO_INDEX => ti_dpo_start,
        TI_INDICATOR_DX_INDEX => ti_dx_start,
        TI_INDICATOR_EDECAY_INDEX => ti_edecay_start,
        TI_INDICATOR_EMA_INDEX => ti_ema_start,
        TI_INDICATOR_EMV_INDEX => ti_emv_start,
        TI_INDICATOR_EXP_INDEX => ti_exp_start,
        TI_INDICATOR_FLOOR_INDEX => ti_floor_start,
        TI_INDICATOR_FOSC_INDEX => ti_fosc_start,
        TI_INDICATOR_HA_INDEX => ti_ha_start,
        TI_INDICATOR_HALF_TREND_INDEX => ti_half_trend_start,
        TI_INDICATOR_HEATMAP_VOL_INDEX => ti_heatmap_vol_start,
        TI_INDICATOR_HLC3_INDEX => ti_hlc3_start,
        TI_INDICATOR_HMA_INDEX => ti_hma_start,
        TI_INDICATOR_HULL_SUITE_INDEX => ti_hull_suite_start,
        TI_INDICATOR_INSIDEBAR_INDEX => ti_insidebar_start,
        TI_INDICATOR_KAMA_INDEX => ti_kama_start,
        TI_INDICATOR_KVO_INDEX => ti_kvo_start,
        TI_INDICATOR_LAG_INDEX => ti_lag_start,
        TI_INDICATOR_LINREG_INDEX => ti_linreg_start,
        TI_INDICATOR_LINREGINTERCEPT_INDEX => ti_linregintercept_start,
        TI_INDICATOR_LINREGSLOPE_INDEX => ti_linregslope_start,
        TI_INDICATOR_LN_INDEX => ti_ln_start,
        TI_INDICATOR_LOG10_INDEX => ti_log10_start,
        TI_INDICATOR_MACD_INDEX => ti_macd_start,
        TI_INDICATOR_MACD_FASTLINE_DIVERGENCE_INDEX => ti_macd_fastline_divergence_start,
        TI_INDICATOR_MACD_HIST_DIVERGENCE_INDEX => ti_macd_hist_divergence_start,
        TI_INDICATOR_MARKETFI_INDEX => ti_marketfi_start,
        TI_INDICATOR_MASS_INDEX => ti_mass_start,
        TI_INDICATOR_MAX_INDEX => ti_max_start,
        TI_INDICATOR_MD_INDEX => ti_md_start,
        TI_INDICATOR_MEDPRICE_INDEX => ti_medprice_start,
        TI_INDICATOR_MFI_INDEX => ti_mfi_start,
        TI_INDICATOR_MIN_INDEX => ti_min_start,
        TI_INDICATOR_MOBO_BAND_INDEX => ti_mobo_band_start,
        TI_INDICATOR_MOM_INDEX => ti_mom_start,
        TI_INDICATOR_MUL_INDEX => ti_mul_start,
        TI_INDICATOR_NATR_INDEX => ti_natr_start,
        TI_INDICATOR_PRICE_INDEX => ti_price_start,
        TI_INDICATOR_PSAR_INDEX => ti_psar_start,
        TI_INDICATOR_QQE_MOD_INDEX => ti_qqe_mod_start,
        TI_INDICATOR_ROC_INDEX => ti_roc_start,
        TI_INDICATOR_ROCR_INDEX => ti_rocr_start,
        TI_INDICATOR_ROUND_INDEX => ti_round_start,
        TI_INDICATOR_RSI_INDEX => ti_rsi_start,
        TI_INDICATOR_RSI_DIVERGENCE_INDEX => ti_rsi_divergence_start,
        TI_INDICATOR_RVI_INDEX => ti_rvi_start,
        TI_INDICATOR_RVI_DIVERGENCE_INDEX => ti_rvi_divergence_start,
        TI_INDICATOR_SIN_INDEX => ti_sin_start,
        TI_INDICATOR_SINH_INDEX => ti_sinh_start,
        TI_INDICATOR_SMA_INDEX => ti_sma_start,
        TI_INDICATOR_SQRT_INDEX => ti_sqrt_start,
        TI_INDICATOR_SSL_INDEX => ti_ssl_start,
        TI_INDICATOR_STC_INDEX => ti_stc_start,
        TI_INDICATOR_STDDEV_INDEX => ti_stddev_start,
        TI_INDICATOR_STDERR_INDEX => ti_stderr_start,
        TI_INDICATOR_STOCH_INDEX => ti_stoch_start,
        TI_INDICATOR_STOCH_DIVERGENCE_INDEX => ti_stoch_divergence_start,
        TI_INDICATOR_STOCHRSI_INDEX => ti_stochrsi_start,
        TI_INDICATOR_SUB_INDEX => ti_sub_start,
        TI_INDICATOR_SUM_INDEX => ti_sum_start,
        TI_INDICATOR_SUP_AND_RES_INDEX => ti_sup_and_res_start,
        TI_INDICATOR_SUPERTREND_INDEX => ti_supertrend_start,
        TI_INDICATOR_TAN_INDEX => ti_tan_start,
        TI_INDICATOR_TANH_INDEX => ti_tanh_start,
        TI_INDICATOR_TEMA_INDEX => ti_tema_start,
        TI_INDICATOR_TODEG_INDEX => ti_todeg_start,
        TI_INDICATOR_TORAD_INDEX => ti_torad_start,
        TI_INDICATOR_TR_INDEX => ti_tr_start,
        TI_INDICATOR_TRIMA_INDEX => ti_trima_start,
        TI_INDICATOR_TRIX_INDEX => ti_trix_start,
        TI_INDICATOR_TRUNC_INDEX => ti_trunc_start,
        TI_INDICATOR_TSF_INDEX => ti_tsf_start,
        TI_INDICATOR_TYPPRICE_INDEX => ti_typprice_start,
        TI_INDICATOR_ULTOSC_INDEX => ti_ultosc_start,
        TI_INDICATOR_UNSHIFT_INDEX => ti_unshift_start,
        TI_INDICATOR_UT_BOT_INDEX => ti_ut_bot_start,
        TI_INDICATOR_VAR_INDEX => ti_var_start,
        TI_INDICATOR_VHF_INDEX => ti_vhf_start,
        TI_INDICATOR_VOLATILITY_INDEX => ti_volatility_start,
        TI_INDICATOR_VOLATILITY_OSCILLATOR_INDEX => ti_volatility_oscillator_start,
        TI_INDICATOR_VOSC_INDEX => ti_vosc_start,
        TI_INDICATOR_VU_MAN_CHU_SWING_INDEX => ti_vu_man_chu_swing_start,
        TI_INDICATOR_VWMA_INDEX => ti_vwma_start,
        TI_INDICATOR_WAD_INDEX => ti_wad_start,
        TI_INDICATOR_WADDAH_INDEX => ti_waddah_start,
        TI_INDICATOR_WAVETREND_INDEX => ti_wavetrend_start,
        TI_INDICATOR_WCPRICE_INDEX => ti_wcprice_start,
        TI_INDICATOR_WILDERS_INDEX => ti_wilders_start,
        TI_INDICATOR_WILLR_INDEX => ti_willr_start,
        TI_INDICATOR_WMA_INDEX => ti_wma_start,
        TI_INDICATOR_ZLEMA_INDEX => ti_zlema_start,
        _ => return Err(IndicatorError::InvalidIndicatorIndex(index)),
    };
    Ok((indicator, start))
}

fn unshift(value: Vec<f64>, length: usize, default_value: f64) -> Vec<f64> {
    let mut pre = vec![default_value; length];
    pre.extend(value);
    pre
}

#[derive(Debug, Clone, PartialEq)]
pub struct DemaInput {
    pub close: Vec<f64>,
}
#[derive(Debug, Clone, PartialEq, Validate)]
pub struct DemaOption {
    #[validate(range(min = 1))]
    pub period: u64,
}
#[derive(Debug, Clone, PartialEq)]
pub struct DemaOutput {
    pub dema: Vec<f64>,
}

pub fn dema(input: DemaInput, option: DemaOption) -> Result<DemaOutput, IndicatorError> {
    option.validate()?;
    let (indicator_fn, start_fn) = get_indicator(TI_INDICATOR_DEMA_INDEX)?;
    let inputs = [input.close.as_ptr()].as_ptr();
    let options = [option.period as f64].as_ptr();
    let start = unsafe { start_fn(options) };
    let mut output = vec![0.0; input.close.len() - start as usize];
    let result = unsafe {
        indicator_fn(
            input.close.len() as i32,
            inputs,
            options,
            [output.as_mut_ptr()].as_ptr(),
        )
    };
    match result as u32 {
        TI_OKAY => Ok(DemaOutput {
            dema: unshift(output, start as usize, 0.0),
        }),
        TI_INVALID_OPTION => Err(IndicatorError::InvalidOption("".to_string())),
        TI_OUT_OF_MEMORY => Err(IndicatorError::OutOfMemory),
        _ => Err(IndicatorError::Unknown),
    }
}

#[derive(Debug, Clone, PartialEq, Validate)]
#[validate(schema(function = "validate_supertrend_input"))]
pub struct SupertrendInput {
    pub high: Vec<f64>,
    pub low: Vec<f64>,
    pub close: Vec<f64>,
}
fn validate_supertrend_input(input: &SupertrendInput) -> Result<(), ValidationError> {
    let SupertrendInput { high, low, close } = input;
    if high.len() != low.len() || high.len() != close.len() || low.len() != close.len() {
        return Err(ValidationError::new(
            "Length for high, low and close must be equal",
        ));
    }
    Ok(())
}
#[derive(Debug, Clone, PartialEq, Validate)]
pub struct SupertrendOption {
    #[validate(range(min = 1))]
    pub atr_period: u64,
    pub atr_factor: f64,
}
#[derive(Debug, Clone, PartialEq)]
pub struct SupertrendOutput {
    pub supertrend: Vec<f64>,
    pub direction: Vec<f64>,
    pub bar_color: Vec<f64>,
    pub buy_sell_signal: Vec<f64>,
}

pub fn supertrend(
    input: SupertrendInput,
    option: SupertrendOption,
) -> Result<SupertrendOutput, IndicatorError> {
    input.validate()?;
    option.validate()?;
    let (indicator_fn, start_fn) = get_indicator(TI_INDICATOR_SUPERTREND_INDEX)?;
    let inputs = [
        input.high.as_ptr(),
        input.low.as_ptr(),
        input.close.as_ptr(),
    ]
    .as_ptr();
    let options = [option.atr_period as f64, option.atr_factor].as_ptr();
    let start = unsafe { start_fn(options) };
    let mut supertrend = vec![0.0; input.close.len() - start as usize];
    let mut direction = vec![DirectionSignal::Nothing; input.close.len() - start as usize];
    let mut bar_color = vec![BarColor::Nothing; input.close.len() - start as usize];
    let mut buy_sell_signal = vec![BuySellSignal::Nothing; input.close.len() - start as usize];
    let outputs = [
        supertrend.as_mut_ptr(),
        direction.as_mut_ptr(),
        bar_color.as_mut_ptr(),
        buy_sell_signal.as_mut_ptr(),
    ]
    .as_ptr();
    let result = unsafe { indicator_fn(input.close.len() as i32, inputs, options, outputs) };
    match result as u32 {
        TI_OKAY => Ok(SupertrendOutput {
            supertrend: unshift(supertrend, start as usize, 0.0),
            direction,
            bar_color,
            buy_sell_signal,
        }),
        TI_INVALID_OPTION => Err(IndicatorError::InvalidOption("".to_string())),
        TI_OUT_OF_MEMORY => Err(IndicatorError::OutOfMemory),
        _ => Err(IndicatorError::Unknown),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_unshift() {
        assert_eq!(
            unshift(vec![1.2, 3.4, 2.3], 2, 0.0),
            vec![0.0, 0.0, 1.2, 3.4, 2.3]
        );
    }

    #[test]
    fn test_dema() {
        let close = vec![
            122.906, 126.500, 140.406, 174.000, 159.812, 170.000, 176.750, 175.531, 166.562,
            163.750, 170.500, 175.000, 184.750, 202.781,
        ];
        assert_eq!(
            dema(DemaInput { close }, DemaOption { period: 5 })
                .unwrap()
                .dema,
            vec![
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                172.07796524919985,
                168.57183020880964,
                170.22778905654627,
                173.4940164270352,
                180.52967121091524,
                194.14277653587135
            ]
        );
    }

    #[test]
    fn test_supertrend() {
        let high = vec![
            23509.68, 23459.89, 23647.68, 23223.32, 23472.86, 23354.36, 23402.0, 24245.0, 23933.25,
            24226.0, 24918.54, 24456.5, 24888.0, 25047.56, 25211.32,
        ];
        let low = vec![
            22850.0, 22654.37, 22681.22, 22400.0, 22586.95, 22909.52, 22844.62, 23154.25, 22865.0,
            22664.69, 23852.13, 23583.0, 24291.22, 24144.0, 23773.22,
        ];
        let close = vec![
            23268.01, 22987.79, 22818.37, 22622.98, 23312.42, 22954.21, 23174.39, 23810.0,
            23149.95, 23954.05, 23934.39, 24403.68, 24441.38, 24305.24, 24094.82,
        ];
        assert_eq!(
            supertrend(
                SupertrendInput { high, low, close },
                SupertrendOption {
                    atr_period: 2,
                    atr_factor: 1.0
                }
            )
            .unwrap(),
            SupertrendOutput {
                supertrend: vec![
                    0.0,
                    23789.729999999996,
                    23789.729999999996,
                    23648.085,
                    23648.085,
                    23648.085,
                    23648.085,
                    22851.654062499998,
                    22851.654062499998,
                    22851.654062499998,
                    23222.2748828125,
                    23222.2748828125,
                    23782.079970703126,
                    23782.079970703126,
                    23782.079970703126
                ],
                direction: vec![
                    DirectionSignal::Nothing,
                    DirectionSignal::Up,
                    DirectionSignal::Up,
                    DirectionSignal::Up,
                    DirectionSignal::Up,
                    DirectionSignal::Up,
                    DirectionSignal::Up,
                    DirectionSignal::Down,
                    DirectionSignal::Down,
                    DirectionSignal::Down,
                    DirectionSignal::Down,
                    DirectionSignal::Down,
                    DirectionSignal::Down,
                    DirectionSignal::Down,
                    DirectionSignal::Down
                ],
                bar_color: vec![
                    BarColor::Red,
                    BarColor::Red,
                    BarColor::Red,
                    BarColor::Red,
                    BarColor::Red,
                    BarColor::Red,
                    BarColor::Red,
                    BarColor::Green,
                    BarColor::Green,
                    BarColor::Green,
                    BarColor::Green,
                    BarColor::Green,
                    BarColor::Green,
                    BarColor::Green,
                    BarColor::Green
                ],
                buy_sell_signal: vec![
                    BuySellSignal::Nothing,
                    BuySellSignal::Nothing,
                    BuySellSignal::Nothing,
                    BuySellSignal::Nothing,
                    BuySellSignal::Nothing,
                    BuySellSignal::Nothing,
                    BuySellSignal::Nothing,
                    BuySellSignal::Buy,
                    BuySellSignal::Nothing,
                    BuySellSignal::Nothing,
                    BuySellSignal::Nothing,
                    BuySellSignal::Nothing,
                    BuySellSignal::Nothing,
                    BuySellSignal::Nothing,
                    BuySellSignal::Nothing
                ]
            }
        );
    }
}
