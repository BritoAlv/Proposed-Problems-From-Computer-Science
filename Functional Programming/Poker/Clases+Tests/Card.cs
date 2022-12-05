public class Card
{
    public Card(CardValue value, CardSuit suit)
    {
        Value = value;
        Suit = suit;
    }

    public CardValue Value { get; }
    public CardSuit Suit { get; }

    public override string ToString() => $"Un {this.Value} de {this.Suit}";
}
