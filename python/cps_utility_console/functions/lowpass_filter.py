"""
CPS Utility Console — Low-Pass IIR Filter
Author: Dominik Żurek
"""


def lowpass_filter(samples: list[float], alpha: float) -> list[float]:
    """
    Apply 1st-order IIR low-pass filter to samples.

    Formula: y[k] = α·x[k] + (1-α)·y[k-1]

    Args:
        samples: Non-empty list of input samples.
        alpha: Smoothing factor, must be in [0.0, 1.0].
               alpha=1.0 : no filtering (output = input)
               alpha=0.0 : maximum smoothing (output = constant)

    Returns:
        List of filtered samples (same length as input).

    Raises:
        ValueError: If samples is empty or alpha is out of range.
    """
    if len(samples) == 0:
        raise ValueError("Samples list cannot be empty.")

    if not (0.0 <= alpha <= 1.0):
        raise ValueError(f"Alpha must be in [0.0 : 1.0], got {alpha}.")

    output = []
    y_prev = samples[0] 

    for x in samples:
        y = alpha * x + (1 - alpha) * y_prev
        output.append(y)
        y_prev = y

    return output