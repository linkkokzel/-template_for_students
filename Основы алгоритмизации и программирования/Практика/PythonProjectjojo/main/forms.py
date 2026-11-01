from django import forms
from django.core.validators import MinValueValidator, MaxValueValidator, RegexValidator
from django.core.exceptions import ValidationError


class DeliveryForm(forms.Form):
    # Доступные типы доставки
    DELIVERY_CHOICES = [
        ('standard', 'Стандартная'),
        ('express', 'Экспресс'),
        ('same_day', 'В тот же день'),
    ]

    full_name = forms.CharField(
        label='ФИО отправителя',
        max_length=100,
        widget=forms.TextInput(attrs={'placeholder': 'Иванов Иван Иванович'})
    )

    phone = forms.CharField(
        label='Телефон',
        validators=[
            RegexValidator(
                regex=r'^\+?7?\d{10,11}$',
                message='Введите номер в формате +7XXXXXXXXXX'
            )
        ],
        widget=forms.TextInput(attrs={'placeholder': '+79991234567'})
    )

    city_from = forms.CharField(
        label='Город отправки',
        max_length=50,
        widget=forms.TextInput(attrs={'placeholder': 'Москва'})
    )

    city_to = forms.CharField(
        label='Город получения',
        max_length=50,
        widget=forms.TextInput(attrs={'placeholder': 'Санкт-Петербург'})
    )

    weight = forms.FloatField(
        label='Вес (кг)',
        validators=[
            MinValueValidator(0.1, message='Вес должен быть не менее 0.1 кг.'),
            MaxValueValidator(100.0, message='Вес не должен превышать 100 кг.')
        ],
        widget=forms.NumberInput(attrs={'step': '0.1'})
    )

    delivery_type = forms.ChoiceField(
        label='Тип доставки',
        choices=DELIVERY_CHOICES
    )

    agree = forms.BooleanField(
        label='Согласен с условиями доставки',
        required=True,
        error_messages={'required': 'Необходимо согласиться с условиями.'}
    )

    def clean(self):
        cleaned_data = super().clean()
        city_from = cleaned_data.get('city_from')
        city_to = cleaned_data.get('city_to')
        weight = cleaned_data.get('weight')
        delivery_type = cleaned_data.get('delivery_type')

        # Валидация: города не должны совпадать
        if city_from and city_to and city_from.lower().strip() == city_to.lower().strip():
            raise ValidationError('Город отправления и город получения не могут совпадать.')

        # Валидация: для express вес должен быть <= 20 кг
        if delivery_type == 'express' and weight and weight > 20.0:
            raise ValidationError({'weight': 'Для экспресс-доставки вес не должен превышать 20 кг.'})

        return cleaned_data
