from django.shortcuts import render
from .forms import DeliveryForm


def delivery_calculator(request):
    form = DeliveryForm(request.POST or None)
    result_cost = None

    if request.method == 'POST' and form.is_valid():
        data = form.cleaned_data

        # Базовая ставка 300 ₽ + 30 ₽ за каждый кг
        base_cost = 300 + (30 * data['weight'])

        # Наценка по типу доставки
        multipliers = {
            'standard': 1.0,
            'express': 1.5,
            'same_day': 2.0
        }
        multiplier = multipliers.get(data['delivery_type'], 1.0)

        # Итоговая стоимость с округлением до 2 знаков
        total_cost = base_cost * multiplier
        result_cost = round(total_cost, 2)

    return render(request, 'main/index.html', {'form': form, 'result_cost': result_cost})
