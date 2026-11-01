from django.urls import path
from .views import delivery_calculator

urlpatterns = [
    path('', delivery_calculator, name='delivery_calculator'),
]
